//------------------------top 모듈-------------------------------
//-----------------------------------------------------------------------------------



module multiple_watch(
    input clk,reset_p,
    input [3:0] button,
    input sw,
    output [7:0] seg,
    output [3:0] com,
    output [15:0] led);
    
    wire [3:0] btn_pedge, btn_nedge;
    button_cntr btncntr0( .clk(clk), .reset_p(reset_p), .btn(button[0]),
                               .btn_pedge(btn_pedge[0]), .btn_nedge(btn_nedge[0]));
    button_cntr btncntr1( .clk(clk), .reset_p(reset_p), .btn(button[1]),
                               .btn_pedge(btn_pedge[1]), .btn_nedge(btn_nedge[1]));
    button_cntr btncntr2( .clk(clk), .reset_p(reset_p), .btn(button[2]),
                               .btn_pedge(btn_pedge[2]), .btn_nedge(btn_nedge[2]));
    button_cntr btncntr3( .clk(clk), .reset_p(reset_p), .btn(button[3]),
                               .btn_pedge(btn_pedge[3]), .btn_nedge(btn_nedge[3]));
                               
    wire [2:0] mode_select;                         
    ring_counter_3 r3( .clk(clk), .reset_p(reset_p),.btn_ring(btn_pedge[3]), .q(mode_select));
    
    wire enable_watch = (mode_select == 3'b001);
    wire enable_cook  = (mode_select == 3'b010);
    wire enable_stop  = (mode_select == 3'b100); 
    
    assign led[5]= enable_watch;
    assign led[4]= enable_cook;
    assign led[3]= enable_stop;
    
//---------------------------------------------------------    
    
    wire[7:0] w_sec,w_min;
    watch watch0(.clk(clk), .reset_p(reset_p), .enable(enable_watch),.btn(btn_pedge[2:0]) ,.sec(w_sec), .min(w_min));
    
    wire [7:0] w_sec_bcd,w_min_bcd;
    bin_to_dec btd_sec( .bin(w_sec), .bcd(w_sec_bcd));
    bin_to_dec btd_min( .bin(w_min), .bcd(w_min_bcd));
//----------------------------------------------------------------
    
    
    
    wire [7:0] sec,min;  
    wire alarm;
    cook_timer ctimer(.clk(clk), .reset_p(reset_p), .enable(enable_cook),
                    .btn_start(btn_pedge[0]), .inc_sec(btn_pedge[1]),
                    .inc_min(btn_pedge[2]), .alarm_off(sw),
                    .sec(sec) , .min(min), .alarm(alarm));
    
    assign led[2] = enable_cook? alarm :1'b0;
    
    wire [7:0] sec_bcd,min_bcd;  
    bin_to_dec c_btd_sec( .bin(sec), .bcd(sec_bcd));
    bin_to_dec c_btd_min( .bin(min), .bcd(min_bcd));
    
    
 //-------------------------------------------------------------------
    wire [7:0] fnd_sec,fnd_c_sec; 
    wire start_stop, lap;
    stop_watch2 sw0(.clk(clk), .reset_p(reset_p), .enable(enable_stop),
                   .btn_start(btn_pedge[0]), .btn_lap(btn_pedge[1]),
                    .btn_clear(btn_pedge[2]),
                    .fnd_sec(fnd_sec), .fnd_csec(fnd_c_sec),
                    .start_stop(start_stop), .lap(lap));
     
    assign led[0] = enable_stop? start_stop :1'b0;
    assign led[1] = enable_stop? lap :1'b0;
     
    wire [7:0] s_sec_bcd,s_c_sec_bcd;  
   
    bin_to_dec s_btd_sec( .bin(fnd_sec), .bcd(s_sec_bcd));
    bin_to_dec s_btd_c_sec ( .bin(fnd_c_sec), .bcd(s_c_sec_bcd));
//-----------------------------------------------------------              
    
    reg [15:0] fnd_value_sel;

    always @(*) begin
        case (mode_select)
            3'b001: fnd_value_sel = {w_min_bcd, w_sec_bcd};
            3'b010: fnd_value_sel = {min_bcd, sec_bcd};
            3'b100: fnd_value_sel = {s_sec_bcd, s_c_sec_bcd};
            default: fnd_value_sel = 16'h0000;
        endcase
    end
    
    
    FND_cntr fnd(.clk(clk), .reset_p(reset_p), .fnd_value(fnd_value_sel), .seg(seg), .com(com));
    
endmodule





//-----------------------------------------------------------------------
//-----------버튼 디마운스 제거---   controll.v참고-----------------------------------------
//-----------------------------------------------------------------------
//------------------ring_counter_3---------------------------------------------

module ring_counter_3(
    input clk, reset_p,
    input btn_ring,
    output reg [2:0] q);
    
    always @(posedge clk, posedge reset_p)begin
        if(reset_p)q=3'b001;
        else begin 
            if(btn_ring)begin
                if(q !=3'b001 && q !=3'b010 && q !=3'b100) q=3'b001;
                else q= {q[1:0],q[2]};  //좌시프트 
            end
        end
    end

endmodule

//-----------------------------------------------------------------------
//------------------------enable_watch------------------------------------------

module watch(
    input clk, reset_p,
    input enable,          // ⭐ 추가된 포트 (Top 제어용)
    input [2:0] btn,
    output reg [7:0] sec, min
);
    
    reg set_watch; //1이면 set 0이면 watch
    always @(posedge clk, posedge reset_p) begin
        if (reset_p)
            set_watch = 0;
        else if (enable && btn[0])   // ⭐ enable만 추가
            set_watch = ~set_watch;
    end
    
    integer cnt_sysclk;

    always @(posedge clk, posedge reset_p) begin
        if (reset_p) begin
            cnt_sysclk = 0;
            sec = 0;
            min = 0;
        end
        else if (enable) begin       // ⭐ enable 가드만 추가
            if (set_watch) begin
                if (btn[1]) begin
                    if (sec >= 59) sec = 0;
                    else sec = sec + 1;
                end
                if (btn[2]) begin
                    if (min >= 59) min = 0;
                    else min = min + 1;
                end
            end
            else begin
                if (cnt_sysclk >= 27'd99_999_999) begin
                    cnt_sysclk = 0;
                    if (sec >= 59) begin
                        sec = 0;
                        if (min >= 59) min = 0;
                        else min = min + 1;
                    end
                    else sec = sec + 1;
                end
                else cnt_sysclk = cnt_sysclk + 1;
            end
        end
    end
endmodule

//-----------------------------------------------------------------------
//------------------------enable_cook------------------------------------------

module cook_timer(
    input clk, reset_p,
    input enable,              // ⭐ 추가
    input btn_start, inc_sec, inc_min, alarm_off,
    output reg [7:0] sec, min,
    output reg alarm
);

    reg dcnt_set;
    reg [7:0] m_sec, m_min;

    always @(posedge clk, posedge reset_p) begin
        if (reset_p) begin
            dcnt_set = 0;
            alarm = 0;
        end
        else if (enable) begin       // ⭐ enable 가드만 추가
            if (btn_start && !(sec == 0 && min == 0))
                dcnt_set = ~dcnt_set;

            if (sec == 0 && min == 0 && dcnt_set) begin
                dcnt_set = 0;
                alarm = 1;
            end

            if (alarm_off || inc_sec || inc_min)
                alarm = 0;

            if (alarm_off && !dcnt_set && !(sec == 0 && min == 0)) begin
                m_min = min;
                m_sec = sec;
            end
        end
    end
    
    integer cnt_sysclk;

    always @(posedge clk, posedge reset_p) begin
        if (reset_p) begin
            cnt_sysclk = 0;
            sec = 0;
            min = 0;
        end
        else if (enable) begin       // ⭐ enable 가드만 추가
            if (dcnt_set) begin
                if (cnt_sysclk >= 99_999_999) begin
                    cnt_sysclk = 0;
                    if (sec == 0 && min) begin
                        sec = 59;
                        min = min - 1;
                    end
                    else
                        sec = sec - 1;
                end
                else
                    cnt_sysclk = cnt_sysclk + 1;
            end
            else begin
                if (inc_sec) begin
                    if (sec >= 59) sec = 0;
                    else sec = sec + 1;
                end
                if (inc_min) begin
                    if (min >= 59) min = 0;
                    else min = min + 1;
                end
                if (alarm_off && !dcnt_set && sec == 0 && min == 0) begin
                    min = m_min;
                    sec = m_sec;
                end
            end
        end
    end
endmodule


//-----------------------------------------------------------------------
//------------------------enable_stopwatch------------------------------------------


module stop_watch2(
    input clk, reset_p,
    input enable,                 // ⭐ 추가
    input btn_start, btn_lap, btn_clear,
    output reg [7:0] fnd_sec, fnd_csec,
    output reg start_stop, lap
);
    
    always @(posedge clk, posedge reset_p) begin
        if (reset_p) begin
            start_stop = 0;
        end
        else if (enable) begin      // ⭐ enable 가드
            if (btn_start)
                start_stop = ~start_stop;
            else if (btn_clear)
                start_stop = 0;
        end
    end
    
    reg [7:0] sec, csec, lap_sec, lap_csec;
    integer cnt_sysclk;

    always @(posedge clk, posedge reset_p) begin
        if (reset_p) begin
            cnt_sysclk = 0;
            sec = 0;
            csec = 0; 
        end
        else if (enable) begin      // ⭐ enable 가드
            if (start_stop) begin
                if (cnt_sysclk >= 999_999) begin
                    cnt_sysclk = 0;
                    if (csec >= 99) begin
                        csec = 0;
                        if (sec >= 59)
                            sec = 0;
                        else
                            sec = sec + 1;
                    end    
                    else
                        csec = csec + 1;
                end
                else
                    cnt_sysclk = cnt_sysclk + 1;
            end
            if (btn_clear) begin
                sec = 0;
                csec = 0;
                cnt_sysclk = 0;
            end
        end
    end
    
    always @(posedge clk, posedge reset_p) begin
        if (reset_p) begin
            lap_sec = 0;
            lap_csec = 0;
            lap = 0;
        end
        else if (enable) begin      // ⭐ enable 가드
            if (btn_lap) begin
                if (start_stop)
                    lap = ~lap;
                lap_sec = sec;
                lap_csec = csec;    
            end
            if (btn_clear) begin
                lap = 0;
                lap_sec = 0;
                lap_csec = 0;
            end
        end
    end
    
    always @(posedge clk, posedge reset_p) begin
        if (reset_p) begin
            fnd_sec = 0;
            fnd_csec = 0;
        end
        else if (enable) begin      // ⭐ enable 가드
            if (lap) begin
                fnd_sec = lap_sec;
                fnd_csec = lap_csec;    
            end
            else begin
                fnd_sec = sec;
                fnd_csec = csec;
            end
        end
    end
endmodule

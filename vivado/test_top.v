`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/04/2025 09:16:19 AM
// Design Name: 
// Module Name: test_top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module test_top(
            input [15:0] slide,
            output [15:0] led );
        
            assign led = slide;
            
endmodule

module FND_top(
    input clk, reset_p,
    input [15:0] hex_value,
    output [7:0] seg,
    output [3:0] com);
     
    FND_cntr fnd(.clk(clk), .reset_p(reset_p), .fnd_value(hex_value), .seg(seg), .com(com));
    
endmodule


module watch_top(
    input clk,reset_p,
    input [3:0] button,
    output [7:0] seg,
    output [3:0] com);
    
    wire [2:0] btn_pedge, btn_nedge;
    button_cntr btncntr0( .clk(clk), .reset_p(reset_p), .btn(button[0]),
                               .btn_pedge(btn_pedge[0]), .btn_nedge(btn_nedge[0]));
    button_cntr btncntr1( .clk(clk), .reset_p(reset_p), .btn(button[1]),
                               .btn_pedge(btn_pedge[1]), .btn_nedge(btn_nedge[1]));
    button_cntr btncntr2( .clk(clk), .reset_p(reset_p), .btn(button[2]),
                               .btn_pedge(btn_pedge[2]), .btn_nedge(btn_nedge[2]));
    
    wire[7:0] sec,min;
    watch watch0(.clk(clk), .reset_p(reset_p), .btn(btn_pedge) ,.sec(sec), .min(min));
    
    wire [7:0] sec_bcd,min_bcd;
    bin_to_dec btd_sec( .bin(sec), .bcd(sec_bcd));
    bin_to_dec btd_min( .bin(min), .bcd(min_bcd));
    
    FND_cntr fnd(.clk(clk), .reset_p(reset_p), .fnd_value({min_bcd,sec_bcd}), .seg(seg), .com(com));
    
endmodule

module cook_timer_top(
    input clk, reset_p,
    input [3:0] button,
    output [7:0] seg,
    output [3:0] com,
    output [15:0] led);


    wire [3:0] btn_pedge, btn_nedge;
    wire alarm;
    
    button_cntr btncntr0( .clk(clk), .reset_p(reset_p), .btn(button[0]),
                               .btn_pedge(btn_pedge[0]), .btn_nedge(btn_nedge[0]));
    button_cntr btncntr1( .clk(clk), .reset_p(reset_p), .btn(button[1]),
                               .btn_pedge(btn_pedge[1]), .btn_nedge(btn_nedge[1]));
    button_cntr btncntr2( .clk(clk), .reset_p(reset_p), .btn(button[2]),
                               .btn_pedge(btn_pedge[2]), .btn_nedge(btn_nedge[2]));
    button_cntr btncntr3( .clk(clk), .reset_p(reset_p), .btn(button[3]),
                               .btn_pedge(btn_pedge[3]), .btn_nedge(btn_nedge[3]));
    
    wire [7:0] sec,min;   //버스일때는 wire 연결해주어야 한다. 한비트때는 자동으로 만들어준다.
    cook_timer ctimer(.clk(clk), .reset_p(reset_p), 
                    .btn_start(btn_pedge[0]), .inc_sec(btn_pedge[1]),
                    .inc_min(btn_pedge[2]), .alarm_off(btn_pedge[3]),
                    .sec(sec) , .min(min), .alarm(alarm));
    
    wire [7:0] sec_bcd,min_bcd;  
    bin_to_dec btd_sec( .bin(sec), .bcd(sec_bcd));
    bin_to_dec btd_min( .bin(min), .bcd(min_bcd));
    
    FND_cntr fnd(.clk(clk), .reset_p(reset_p), .fnd_value({min_bcd,sec_bcd}), .seg(seg), .com(com));
    
   assign led[0] =alarm;
   
endmodule


module stop_watch_top(
    input clk,reset_p,
    input [3:0] button,
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
                               .btn_pedge(btn_pedge[3]), .btn_nedge(btn_nedge[3]));  //현재 시간이랑 latest 랩타입 확인 
                
    wire [7:0] fnd_sec,fnd_c_sec;                       
//    stop_watch swatch(.clk(clk), .reset_p(reset_p), .start_stop(btn_pedge[0]), .lap(btn_pedge[1]),
//                       .clear(btn_pedge[2]),.option(btn_pedge[3]),.fnd_sec(fnd_sec), .fnd_c_sec(fnd_c_sec),
//                       .running_stop(led[0]));
                       
//    stop_watch_btn3 swatch_btn3 (.clk(clk), .reset_p(reset_p), .start_stop(btn_pedge[0]), .lap(btn_pedge[1]),
//                                 .clear(btn_pedge[2]), .fnd_sec(fnd_sec), .fnd_c_sec(fnd_c_sec));                   
    
    stop_watch2 sw0(.clk(clk), .reset_p(reset_p),
                   .btn_start(btn_pedge[0]), .btn_lap(btn_pedge[1]),
                    .btn_clear(btn_pedge[2]),
                    .fnd_sec(fnd_sec), .fnd_csec(fnd_c_sec),
                    .start_stop(led[0]), .lap(led[1]));
    
    
    wire [7:0] sec_bcd,c_sec_bcd;  
   
    bin_to_dec btd_sec( .bin(fnd_sec), .bcd(sec_bcd));
    bin_to_dec btd_c_sec ( .bin(fnd_c_sec), .bcd(c_sec_bcd));
    
    FND_cntr fnd(.clk(clk), .reset_p(reset_p), .fnd_value({sec_bcd,c_sec_bcd}), .seg(seg), .com(com)); 
endmodule

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


module mutifunction_watch_top(
    input clk, reset_p,
    input [3:0] button,
    input [15:0] slide,
    output [7:0] seg,
    output [3:0] com,
    output [15:0] led,
    output buz);
    
    localparam WATCH = 3'b001;
    localparam COOK_TIMER = 3'b010;
    localparam STOPWATCH = 3'b100;  //define이랑 똑같다. 
    
    wire [3:0] btn_pedge, btn_nedge;
    button_cntr btncntr0( .clk(clk), .reset_p(reset_p), .btn(button[0]),
                               .btn_pedge(btn_pedge[0]), .btn_nedge(btn_nedge[0]));
    button_cntr btncntr1( .clk(clk), .reset_p(reset_p), .btn(button[1]),
                               .btn_pedge(btn_pedge[1]), .btn_nedge(btn_nedge[1]));
    button_cntr btncntr2( .clk(clk), .reset_p(reset_p), .btn(button[2]),
                               .btn_pedge(btn_pedge[2]), .btn_nedge(btn_nedge[2]));
    button_cntr btncntr3( .clk(clk), .reset_p(reset_p), .btn(button[3]),
                               .btn_pedge(btn_pedge[3]), .btn_nedge(btn_nedge[3]));
                            
    reg[2:0] mode, next_mode;
    assign led[7:5] =mode;
    always@(*)begin
        if(reset_p)next_mode= WATCH;
        else if(btn_pedge[3])begin
            if(mode == WATCH) next_mode=COOK_TIMER;
            else if(mode == COOK_TIMER && next_mode == COOK_TIMER) next_mode= STOPWATCH;
            else if(mode == STOPWATCH) next_mode= WATCH;
        end
        else if(mode == COOK_TIMER && (btn_pedge[0] || btn_pedge[1] || btn_pedge[2])) next_mode= WATCH;
        else next_mode= WATCH;
    end
    always@(posedge clk, posedge reset_p)begin
        if(reset_p)mode=WATCH;
        else if(btn_pedge[3]) begin
            mode= next_mode;
        end
    end
    reg [2:0]watch_btn,cook_btn,stopwatch_btn;
    always @(*)begin  //조합회로여서 edge 안쓴다.
        case(mode)
            WATCH: begin
                watch_btn=btn_pedge[2:0];
                cook_btn=0;
                stopwatch_btn=0;
            end
            COOK_TIMER: begin
                watch_btn=0;
                cook_btn=btn_pedge[2:0];
                stopwatch_btn=0;
            end
            STOPWATCH: begin
                watch_btn=0;
                cook_btn=0;
                stopwatch_btn=btn_pedge[2:0];
            end
        endcase
    end
                             
    wire[7:0] watch_sec,watch_min;
    watch watch0(.clk(clk), .reset_p(reset_p), .enable(1), .btn(watch_btn) ,.sec(watch_sec), .min(watch_min));
    
    wire [7:0] cook_sec,cook_min; 
    wire alarm; 
    cook_timer ctimer(.clk(clk), .reset_p(reset_p), .enable(1),
                    .btn_start(cook_btn[0]), .inc_sec(cook_btn[1]),
                    .inc_min(cook_btn[2]), .alarm_off(slide[0]),
                    .sec(cook_sec) , .min(cook_min), .alarm(alarm));
                    
                    
    wire [7:0] stopwatch_sec,stopwatch_csec;                       
    wire start_stop,lap;
    assign led[0]= start_stop;
    assign led[1]= lap;
    stop_watch2 sw0(.clk(clk), .reset_p(reset_p),.enable(1),
                    .btn_start(stopwatch_btn[0]), .btn_lap(stopwatch_btn[1]),
                    .btn_clear(stopwatch_btn[2]),
                    .fnd_sec(stopwatch_sec), .fnd_csec(stopwatch_csec),
                    .start_stop(start_stop), .lap(lap));
    
    wire [7:0] bcd_low,bcd_high, bin_low,bin_high;  
    
    
    assign bin_low = mode == COOK_TIMER ? cook_sec:
                     mode == STOPWATCH ? stopwatch_csec : watch_sec;
    assign bin_high = mode == COOK_TIMER ? cook_min:
                      mode == STOPWATCH ? stopwatch_sec : watch_min;
                
   
    bin_to_dec btd_low(.bin(bin_low), .bcd(bcd_low));
    bin_to_dec btd_high (.bin(bin_high), .bcd(bcd_high));
    
    FND_cntr fnd(.clk(clk), .reset_p(reset_p), .fnd_value({bcd_high,bcd_low}), .seg(seg), .com(com)); 
    
    assign buz =alarm;
    assign led[15] =alarm;
   
endmodule


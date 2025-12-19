`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/19/2025 01:31:11 PM
// Design Name: 
// Module Name: ChristmasTree_top
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


module ChristmasTree_top(
    input clk, reset_p,
    input [3:0] button,
    output speaker,
    output [15:0] led
);
    // --- 1. 버튼 컨트롤러 (0번: 전원, 1번: 곡 전환) ---
    wire [3:0] btn_pedge;
    button_cntr btn0(.clk(clk), .reset_p(reset_p), .btn(button[0]), .btn_pedge(btn_pedge[0]));
    button_cntr btn1(.clk(clk), .reset_p(reset_p), .btn(button[1]), .btn_pedge(btn_pedge[1]));

    // --- 2. 상태 제어 레지스터 ---
    reg play_stop;          // 0: Stop, 1: Play
    reg [4:0] song_sel;     // 현재 선택된 곡 (One-hot)
    
    localparam S1=5'b00001, S2=5'b00010, S3=5'b00100, S4=5'b01000, S5=5'b10000;

    // 전원 제어 (Button 0)
    always @(posedge clk or posedge reset_p) begin
        if(reset_p) play_stop <= 1'b0;
        else if(btn_pedge[0]) play_stop <= ~play_stop;
    end

    // 곡 전환 제어 (Button 1)
    always @(posedge clk or posedge reset_p) begin
        if(reset_p) song_sel <= S1;
        else if(btn_pedge[1]) begin
            case(song_sel)
                S1: song_sel <= S2;
                S2: song_sel <= S3;
                S3: song_sel <= S4;
                S4: song_sel <= S5;
                S5: song_sel <= S1;
                default: song_sel <= S1;
            endcase
        end
    end

    // --- 3. 음악 시스템 연결 ---
    music_player_system music_inst (
        .clk(clk),
        .reset_p(reset_p),
        .play_stop(play_stop), // 전원 신호 추가
        .song_sel(song_sel),
        .speaker(speaker)
    );

    // --- 4. LED 표시 (상위 8비트: 전원 상태, 하위 5비트: 곡 번호) ---
    assign led = { {8{play_stop}}, 3'b0, song_sel };

endmodule
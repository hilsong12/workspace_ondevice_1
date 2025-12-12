`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/12/2025 09:04:01 AM
// Design Name: 
// Module Name: attitude_core
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


module attitude_core(
    input clk, reset_p,
    input sw,
    output [7:0] led );
    
    reg signed [7:0] angular_rate; 
    always@(posedge clk, posedge reset_p)begin 
        if(reset_p) angular_rate=0; 
        else if(sw) angular_rate = 8'sd1; 
         else angular_rate = -8'sd1; 
    end


    reg [19:0] sysclk;
    wire tick = (sysclk == 20'd999_999);

    always @(posedge clk, posedge reset_p) begin
        if (reset_p)
            sysclk <= 0;
        else if (tick)
            sysclk <= 0;
        else
            sysclk <= sysclk + 1;
    end


    reg signed [15:0] angle;
    always @(posedge clk, posedge reset_p)begin
        if(reset_p)
            angle <=0;
        else if(tick)
            angle <= angle +angular_rate;
        
    end 
    
    assign led = angle[15:8];

endmodule

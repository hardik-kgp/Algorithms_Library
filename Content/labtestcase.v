// state Encoding 
// A -> 000
// B -> 001
// C -> 010
// D -> 011
// E -> 100

// the bits are numbered as a,b,c from left to right

// Excitation functions of flip flops 

// Ja,Ka are parameters for 1st bit of state (msb)
// Jb,Kb are parameters for 2nd bit of state
// Jc,Kc are parameters for 3rd  bit of state (msb)

// function for Ja = i1.i2 + c.i2 + b.i2 + b.i1
// function for Ka = 0
// function for Jb = a'.i1.i2'	
// function for Kb = c + i1 + i2
// function for Jc = b.i1'.i2' + a'.b'.i1'.i2
// function for Kc = 1

// Output function
// o1 = a'b'c' 


// Excitation functions for next state

// a(next) = a + i1.i2 + c.i2 + b.i2 + b.i1
// b(next) = a'.b'.i1.i2' + b.c'.i1'.i2'
// c(next) = b.c'.i1'.i2' + a'.b'.c'.i1'.i2
module jkff(clk,j,k,,q,qbar,rst);

input clk,j,k,rst;
output reg q,qbar;


always@(posedge clk or posedge rst)
begin
if (rst)
    begin
        q <= 0;
        qbar <= 1;
    end
else
    begin
    if(k == 0 && j == 1)
    begin
        q <= 1;
        qbar <= 0;
    end
    else if(j == 0 && k == 1)
    begin
        q <= 0;
        qbar <= 1;
    end
    else if(j == 0 & k == 0)
    begin
        q <= q;
        qbar <= qbar;
    end
    else if(j == 1 & k == 1)
    begin
        q <= ~q;
        qbar <= ~qbar;
    end
    end
end
endmodule



module fetch_jk(curr_state, in, ja, ka, jb, kb, jc, kc);

	input [2:0] curr_state;
	input [1:0] in;
	output wire ja, ka, jb, kb, jc, kc;

	wire a, b, c, i1, i2;
	assign a = curr_state[2], b = curr_state[1], c = curr_state[0], i1 = in[1], i2 = in[0];

	assign ja = ( (i1&i2) | (c&i2) | (b&i2) | (b&i1) );
	assign ka = 0;
	assign jb = ( ~a&i1&~i2 );
	assign kb = ( c | i1 | i2 );
	assign jc = ( (b&~i1&~i2) | (~a&~b&~i1&i2) );

endmodule

`timescale 1ns / 1ps

module moore(i1,i2,clk,rst,o1);

input i1,i2,clk,rst;
output reg o1;
parameter A = 3'b000,B = 3'b001,C = 3'b010,D = 3'b011,E = 3'b100;
reg state ;
always @(posedge clk or posedge rst)
begin
	if(rst)
		begin
			state <= A;
		end
	else
		case(state)
			A:begin
				if(i1 ==0 && i2 == 0 )
					state <= A;
				else if(i1 == 0 && i2 == 1)
					state <= C;
				else if (i1 == 1 && i2 == 0)
					state <= B;
				else 
					state <= E;
			end
			B: begin
				if(i1 == 0 && i2 == 0)
					state <= D;
				else if(i1 == 0 && i2 == 1)
					state <= E;
				else if (i1 == 1 && i2 == 0)
					state <= E;
				else 
					state <= E;
			end
			C: begin
				if(i1 == 0 && i2 == 0)
					state <= A;
				else if(i1 == 0 && i2 == 1)
					state <= E;
				else if (i1 == 1 && i2 == 0)
					state <= B;
				else 
					state <= E;
			end
			D: begin
				if(i1 == 0 && i2 == 0)
					state <= A;
				else if(i1 == 0 && i2 == 1)
					state <= E;
				else if (i1 == 1 && i2 == 0)
					state <= E;
				else 
					state <= E;
			end
			E: begin
				if(i1 == 0 && i2 == 0)
					state <= E;
				else if(i1 == 0 && i2 == 1)
					state <= E;
				else if (i1 == 1 && i2 == 0)
					state <= E;
				else 
					state <= E;
			end
			default : state <=A;
		endcase
			
end
always @(posedge clk or posedge rst)
begin
	if(state == A)
		o1 = 1;
	else
		o1 = 0;
end		
endmodule

module testbench;

reg i1,i2,clk,rst;
wire o1;
moore m1(i1,i2,clk,rst,o1);

initial 
begin
	clk = 1'b0;
	#2 rst = 1;
	#5 rst = 0;
end
always  #5 clk = ~clk;
initial
begin
	#12 i1 = 1; i2 = 0;
	#10 i1 = 0;i2 = 0;
	#10 i1 = 0;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#20 ;
	rst = 1'b1;
	#10 i1 = 0;i2 = 1;
	#10 i1 = 1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 1;
    #10 rst = 1'b0;
	#20;
	rst = 1'b1;
	#10 i1 = 0;i2 = 1;
	#10 i1 = 0;i2 = 0;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 1;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
    #10 rst = 1'b0;
	#20;
	rst = 1'b1;
	#10 i1 = 0;i2 = 1;
	#10 i1 = 0;i2 = 1;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 0;
    #10 rst = 1'b0;
	#500 $finish;
end

initial
begin
	
	$monitor($time," i1 = %b, i2 = %b, o = %b",i1,i2,o1);
end


endmodule // 



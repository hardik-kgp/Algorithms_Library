// 18CS10021
// Hardik Aggarwal
`timescale 1ns / 1ps
// state Encoding 
// A -> 000
// B -> 001
// C -> 010
// D -> 011
// E -> 100

// the bits are numbered as a,b,c from left to right

// Excitation functions of flip flops ///

// Ja,Ka are parameters for 1st bit of state (msb)
// Jb,Kb are parameters for 2nd bit of state
// Jc,Kc are parameters for 3rd  bit of state (msb)

// function for Ja = i1.i2 + c.i2 + b.i2 + b.i1
// function for Ka = 0
// function for Jb = a'.i1.i2'	
// function for Kb = c + i1 + i2
// function for Jc = b.i1'.i2' + a'.b'.i1'.i2
// function for Kc = 1



// Output function///
// o1 = a'b'c' 


// Excitation functions for next state///

// a(next) = a + i1.i2 + c.i2 + b.i2 + b.i1
// b(next) = a'.b'.i1.i2' + b.c'.i1'.i2'
// c(next) = b.c'.i1'.i2' + a'.b'.c'.i1'.i2




/// total behavourial code ////////


// module moore1(i1,i2,clk,rst,o1);

// input i1,i2,clk,rst;

// output o1;
// localparam A = 3'b000,B = 3'b001,C = 3'b010,D = 3'b011,E = 3'b100;
// reg state ;
// always @(posedge clk or posedge rst)
// begin
// 	if(rst)
// 		begin
// 			state <= A;
// 		end
// 	else
// 		case(state)
// 			A:begin
// 				if(i1 ==0 && i2 == 0 )
// 					state <= A;
// 				else if(i1 == 0 && i2 == 1)
// 					state <= C;
// 				else if (i1 == 1 && i2 == 0)
// 					state <= B;
// 				else 
// 					state <= E;
// 			end
// 			B: begin
// 				if(i1 == 0 && i2 == 0)
// 					state <= D;
// 				else if(i1 == 0 && i2 == 1)
// 					state <= E;
// 				else if (i1 == 1 && i2 == 0)
// 					state <= E;
// 				else 
// 					state <= E;
// 			end
// 			C: begin
// 				if(i1 == 0 && i2 == 0)
// 					state <= A;
// 				else if(i1 == 0 && i2 == 1)
// 					state <= E;
// 				else if (i1 == 1 && i2 == 0)
// 					state <= B;
// 				else 
// 					state <= E;
// 			end
// 			D: begin
// 				if(i1 == 0 && i2 == 0)
// 					state <= A;
// 				else if(i1 == 0 && i2 == 1)
// 					state <= E;
// 				else if (i1 == 1 && i2 == 0)
// 					state <= E;
// 				else 
// 					state <= E;
// 			end
// 			E: begin
// 				if(i1 == 0 && i2 == 0)
// 					state <= E;
// 				else if(i1 == 0 && i2 == 1)
// 					state <= E;
// 				else if (i1 == 1 && i2 == 0)
// 					state <= E;
// 				else 
// 					state <= E;
// 			end
// 			default : state <=A;
// 		endcase
			
// end
// assign o1 = (state == A)? 1'b1 : 1'b0;
// endmodule


/////////////////////////////////////////////////////////////////

module moore(i1,i2,clk,rst,o1);

input i1,i2,clk,rst;
output reg o1;
parameter A = 3'b000,B = 3'b001,C = 3'b010,D = 3'b011,E = 3'b100;     // state encodings
reg state[2:0] ;    // vector for state 
reg ja,ka,jb,kb,jc,kc;
always @(posedge rst)
begin
	state[2] <= 1'b0;
	state[1] <= 1'b0;
	state[0] <= 1'b0;
	o1 <=1;
end

always @(posedge clk or posedge rst)
begin
	//$display("%b %b %b",state[2],state[1],state[0]);
	ja <= (( (((i1&i2) | (state[0]&i2)) | (state[1]&i2)) | (state[1]&i1) ));   // implementation of excitation function
	ka <= 0;
	jb <= ( ((!state[2])&(i1))&(!i2));
	kb <= ( (state[0] | i1) | i2 );
	jc <= ( ((state[1]&(!i1))&(!i2)) | (((!state[2])&(!state[1])&(!i1)&(i2))) );
	kc <= 1'b1;
	
	if(ja == 1 && ka == 0)                                            // implementation of flip flops
		state[2]<=1'b1;
	else if(ka == 1 && ja == 0)
		state[2] <=1'b0;
	else if(ka == 1 && ja == 1)
		state[2] <= ~state[2];
	else
		state[2] <= state[2];

	if(jb == 1 && kb == 0)
		state[1]<=1'b1;
	else if(kb == 1 && jb == 0)
		state[1] <=1'b0;
	else if(kb == 1 && jb == 1)
		state[1] <= ~state[1];
	else
		state[1] <= state[1];

	if(jc == 1 && kc == 0)
		state[0]<=1'b1;
	else if(kc == 1 && jc == 0)
		state[0] <=1'b0;
	else if(kc == 1 && jc == 1)
		state[0] <= ~state[0];
	else
		state[0] <= state[0];


end

always @(state[2],state[1],state[0])
begin
	o1 <= (((!state[0])&(!state[1]))&(!state[2]));      /// implementation of output function
end		
endmodule








module testbench;    // test bench

reg i1,i2,clk,rst;  // inputs 
wire o1;			// outputs
moore m1(i1,i2,clk,rst,o1);    // machine object

always
begin  
	#5 clk = ~clk;
end
initial
begin
	rst = 1'b0;
	clk = 1'b0;
	#2 rst = 1'b1;
	#1 rst = 1'b0;
	#10 i1 = 0;i2 = 1;
	#10 i1 = 1;i2 = 0;
	#10 i1 = 0;i2 = 0;
	#10 i1 = 0;i2 = 0;
	#2 rst = 1'b1;
	#4 rst = 1'b0;
	
	
	#10 i1 = 0;i2 = 1;
	#10 i1 = 1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 1;
	#10 rst = 1'b0;
	#2 rst = 1'b1;
	#4 rst = 1'b0;
	#10 i1 = 0;i2 = 1;
	#10 i1 = 0;i2 = 0;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 1;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 rst = 1'b0;
	#2 rst = 1'b1;
	#4 rst = 1'b0;
	#10 i1 = 0;i2 = 1;
	#10 i1 = 0;i2 = 0;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#10 i1 =  0;i2 = 1;
	#10 i1 =  1;i2 = 0;
	#10 i1 =  0;i2 = 0;
	#1000 $finish;
end

initial
begin
	
	$monitor($time," i1 = %b, i2 = %b, o = %b",i1,i2,o1);   // printing on screen
end


endmodule // 
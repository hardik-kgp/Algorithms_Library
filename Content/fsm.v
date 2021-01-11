module mealy(clk,rst,x,z);
input x,clk,rst;
output reg z;
reg even_odd;
parameter EVEN = 0, ODD = 1;
always @(posedge clk)
	case (even_odd)
		EVEN: begin
			if(x == 1 && x == 1) even_odd = ODD;
			else even_odd = EVEN;
			end
		ODD : begin
			if(x == 1) even_odd = EVEN;
			else even_odd = ODD;
			end
		default  : even_odd = EVEN;
	endcase

always @(even_odd)
	case (even_odd)
	EVEN : z = 0;
	ODD : z = 1;
	endcase
always @(posedge clk ,negedge rst)
	if(rst) even_odd <= EVEN;
endmodule

module test_bench;
reg clk,x,rst;
wire z;
mealy dut(clk,rst,x,z);
initial
	begin clk = 1'b0;
	#2 rst = 1;
	#5 rst = 0;
	end
always #5 clk = ~clk;
initial begin #2 
		repeat (2)
		#10 x = 1;
		#10 x = 0;
		#10 x = 0;
		# 10 x = 1;
	end
initial 
	begin
		$monitor($time,"clk = : %b even_odd =  %b x = %B",clk,z,x);
		#200 $finish;
	end
endmodule





// //Code for Mealy Machine - 
// `timescale 1ms/1ns

// module mealymsb(cl,rst,inp,outp);   // code for module mealy msb
//     input cl;
//     input rst;
//     input inp;
//     output[3:0] outp;
//     reg[3:0] outp;
//     reg[3:0] state; // for state 

//     parameter S0 = 0, S1 = 1,S2 = 2,S3 = 3,S4 = 4; 			// setting the states

//     always@ (posedge cl or posedge rst)
//     begin
//         if(rst)                                        // go to start state
//         	begin
//                 state <= S0;
//                 outp <= 0;
//             end
//         else begin
//             case(state)                                   // check on current state 
//                 S0: if(inp)
//                     	begin
//                         	state <= S1;
//                         	outp <= 1;
//                         end
//                     else
//                         begin
//                             state <= S0;
//                             outp <= 0;
//                         end
//                 S1: if(inp)
//                     	begin
//                             state <= S3;
//                             outp <= 3;
//                         end
//                     else
//                         begin
//                             state <= S2;
//                             outp <= 2;        
//                         end
//                 S2: if(inp)
//                     	begin
//                             state <= S0;
//                             outp <= 0;
//                         end
//                     else
//                         begin
//                             state <= S4;
//                             outp <= 4;
//                         end
//                 S3: if(inp)
//                     	begin
//                             state <= S2;
//                             outp <= 2;
//                         end
//                     else
//                         begin
//                             state <= S1;
//                             outp <= 1;
//                         end
//                 S4: if(inp)
//                     	begin
//                             state <= S4;
//                             outp <= 4;
//                         end
//                 	else
//                         begin
//                             state <= S3;
//                             outp <= 3;
//                         end
//             endcase
//         end
// 	end
// endmodule









// module mooremsb(out, in, rst, clk);										//Code for moore machine msb
// 	output out;
// 	input in;
// 	input clk, rst;
// 	reg out;
// 	reg[2:0] state;
// 	parameter s0=0, s1=1, s2=2, s3=3, s4 = 4;							// setting the states
// 	always @(posedge clk or negedge rst)
// 	begin	
// 		if(rst)																	// go to start state
//         	begin
//                 state <= s0;
//                 out <= 0;
//             end
//         else begin
// 			case (state)						 // check on current state 
// 				s0: if(in)
// 						begin
// 							state <= s0;
// 						end
// 					else
// 						begin
// 							state <=s1;
// 						end
// 				s1: if(in)
// 						begin
// 							state <= s2;
// 						end
// 					else
// 						begin
// 							state <= s3;
// 						end
// 				s2: if(in)
// 						begin
// 							state <= s4;
// 						end
// 					else
// 						begin
// 							state <=s0;
// 						end
// 				s3: if(in)
// 						begin
// 							state <= s1;
// 						end
// 					else
// 						begin
// 							state <=s2;
// 						end
// 				s4: if(in)
// 						begin
// 							state <= s3;
// 						end
// 					else
// 						begin
// 							state <=s4;
// 						end
// 				default: state<=s0;
// 			endcase
// 		end
// 	end
// 	assign out = state;	
	
// endmodule






													
// module moorelsb( clk, rst, inp, outp);				// Code: Moore LSB
// 	input clk, rst, inp;
// 	output outp;
// 	reg [4:0] state;														// setting the states
// 	reg outp;
// 	always @( posedge clk, posedge rst )
// 	begin
// 		if( rst )														// go to start state
// 			state <= 5'b11111;
// 		else
// 			begin
// 				case( state )												 // check on current state 
// 					5'b11111: begin
// 						if( inp ) state <= 5'b00001;
// 						else state <= 5'b00000;
// 					end
// 					5'b00000: begin
// 						if( inp ) state <= 5'b00111;
// 						else state <= 5'b00101;
// 					end
// 					5'b00001: begin
// 						if( inp ) state <= 5'b01000;
// 						else state <= 5'b00110;
// 					end
// 					5'b00010: begin
// 						if( inp ) state <= 5'b01001;
// 						else state <= 5'b00111;
// 					end
// 					5'b00011: begin
// 						if( inp ) state <= 5'b00101;
// 						else state <= 5'b01000;
// 					end
// 					5'b00100: begin
// 						if( inp ) state <= 5'b00110;
// 						else 	state <= 5'b01001;
// 					end
// 					5'b00101: begin
// 						if( inp ) state <= 5'b01110;
// 						else state <= 5'b01010;
// 					end
// 					5'b00110: begin
// 						if( inp ) state <= 5'b01010;
// 						else state <= 5'b01011;
// 					end
// 					5'b00111: begin
// 						if( inp ) state <= 5'b01011;
// 						else state <= 5'b01100;
// 					end
// 					5'b01000: begin
// 						if( inp ) state <= 5'b01100;
// 						else state <= 5'b01101;
// 					end
// 					5'b01001: begin
// 						if( inp ) state <= 5'b01101;
// 						else state <= 5'b01110;
// 					end
// 					5'b01010: begin
// 						if( inp ) state <= 5'b10010;
// 						else state <= 5'b01111;
// 					end
// 					5'b01011: begin
// 						if( inp ) state <= 5'b10011;
// 						else state <= 5'b10000;
// 					end
// 					5'b01100: begin
// 						if( inp ) state <= 5'b01111;
// 						else state <= 5'b10001;
// 					end
// 					5'b01101: begin
// 						if( inp ) state <= 5'b10000;
// 						else state <= 5'b10010;
// 					end
// 					5'b01110: begin
// 						if( inp ) state <= 5'b10001;
// 						else state <= 5'b10011;
// 					end
// 					5'b01111: begin
// 						if( inp ) state <= 5'b00001;
// 						else state <= 5'b00000;
// 					end
// 					5'b10000: begin
// 						if( inp ) state <= 5'b00010;
// 						else state <= 5'b00001;
// 					end
// 					5'b10001: begin
// 						if( inp ) state <= 5'b00011;
// 						else state <= 5'b00010;
// 					end
// 					5'b10010: begin
// 						if( inp ) state <= 5'b00100;
// 						else state <= 5'b00011;
// 					end
// 					5'b10011: begin
// 						if( inp ) state <= 5'b00000;
// 						else state <= 5'b00100;
// 					end
// 				endcase
// 			end
// 	end
// 	always @(posedge clk, posedge rst)
// 	begin
// 		if(state==5'b00000 || state==5'b00101 || state==5'b01010 || state==5'b01111) outp <= 000;
// 		else if(state==5'b00001 || state==5'b00110 || state==5'b01011 || state==5'b10000) outp <= 001;
// 		else if(state==5'b00010 || state==5'b00111 || state==5'b01100 || state==5'b10001) outp <= 010;
// 		else if(state==5'b00011 || state==5'b01000 || state==5'b01101 || state==5'b10010) outp <= 011;
// 		else if(state==5'b00100 || state==5'b01001 || state==5'b01110 || state==5'b10011) outp <= 100;
// 	end	
// endmodule



// module mealylsb( clk, rst, inp, outp);								// Mealy LSB
// 	input clk, rst, inp;
// 	output [2:0] outp;
// 	reg [4:0] state;								// setting the states
// 	reg outp;
// 	always @( posedge clk, posedge rst )
// 	begin
// 		if( rst ) 														// go to start state
// 			begin
// 				state <= 5'b11111;
// 				outp <= 000;
// 			end
// 		else 
// 			begin
// 				case( state )															 // check on current state 
// 					5'b11111: begin
// 						if( inp ) begin
// 							state <= 5'b00001;
// 							outp <= 001;
// 						end
// 						else begin
// 							state <= 5'b00000;
// 							outp <= 000;
// 						end
// 					end
// 					5'b00000: begin
// 						if( inp ) begin
// 							state <= 5'b00111;
// 							outp <= 010;
// 						end
// 						else begin
// 							state <= 5'b00001;
// 							outp <= 001;
// 						end
// 					end
// 					5'b00001: begin
// 						if( inp ) begin
// 							state <= 5'b01000;
// 							outp <= 011;
// 						end
// 						else begin
// 							state <= 5'b00110;
// 							outp <= 001;
// 						end
// 					end
// 					5'b00010: begin
// 						if( inp ) begin
// 								state <= 5'b01001;
// 								outp <= 100;
// 							end
// 						else begin
// 							state <= 5'b00111;
// 							outp <= 010;
// 						end
// 					end
// 					5'b00011: begin
// 						if( inp ) begin
// 							state <= 5'b00101;
// 							outp <= 000;
// 						end
// 						else begin
// 							state <= 5'b01000;
// 							outp <= 011;
// 						end
// 					end
// 					5'b00100: begin
// 						if( inp ) begin
// 							state <= 5'b00110;
// 							outp <= 001;
// 						end
// 						else begin
// 							state <= 5'b01001;
// 							outp <= 100;
// 						end
// 					end
// 					5'b00101: begin
// 						if( inp ) begin
// 							state <= 5'b01110;
// 							outp <= 100;
// 						end
// 						else begin
// 							state <= 5'b01010;
// 							outp <= 000;
// 						end
// 					end
// 					5'b00110: begin
// 						if( inp ) begin
// 							state <= 5'b01010;
// 							outp <= 000;
// 						end
// 						else begin
// 							state <= 5'b01011;
// 							outp <= 001;
// 						end
// 					end
// 					5'b00111: begin	
// 						if( inp ) begin
// 							state <= 5'b01011;
// 							outp <= 001;		
// 						end	
// 						else begin
// 							state <= 5'b01100;
// 							outp <= 010;
// 						end
// 					end
// 					5'b01000: begin
// 						if( inp ) begin
// 							state <= 5'b01100;
// 							outp <= 010;
// 						end
// 						else begin
// 							state <= 5'b01101;
// 							outp <= 011;
// 						end
// 					end
// 					5'b01001: begin
// 						if( inp ) begin
// 							state <= 5'b01101;
// 							outp <= 011;
// 						end
// 						else begin
// 							state <= 5'b01110;
// 							outp <= 100;
// 						end
// 					end
// 					5'b01010: begin
// 						if( inp ) begin
// 							state <= 5'b10010;
// 							outp <= 011;
// 						end
// 						else begin
// 							state <= 5'b01111;
// 							outp <= 000;
// 						end
// 					end
// 					5'b01011: begin
// 						if( inp ) begin
// 							state <= 5'b10011;
// 							outp <= 100;
// 						end
// 						else begin
// 							state <= 5'b10000;
// 							outp <= 001;
// 						end
// 					end
// 					5'b01100: begin
// 						if( inp ) begin
// 							state <= 5'b01111;
// 							outp <= 000;
// 						end
// 						else begin
// 							state <= 5'b10001;
// 							outp <= 001;
// 						end
// 					end
// 					5'b01101: begin
// 						if( inp ) begin
// 							state <= 5'b10000;
// 							outp <= 001;
// 						end
// 						else begin
// 							state <= 5'b10010;
// 							outp <= 011;
// 						end
// 					end
// 					5'b01110: begin
// 						if( inp ) begin
// 							state <= 5'b10001;
// 							outp <= 010;
// 						end
// 						else begin
// 							state <= 5'b10011;
// 							outp <= 100;
// 						end
// 					end
// 					5'b01111: begin
// 						if( inp ) begin
// 							state <= 5'b00001;
// 							outp <= 001;
// 						end
// 						else begin
// 							state <= 5'b00000;
// 							outp <= 000;
// 						end
// 					end
// 					5'b10000: begin
// 						if( inp ) begin
// 							state <= 5'b00010;
// 							outp <= 010;
// 						end
// 						else begin
// 							state <= 5'b00001;
// 							outp <= 001;
// 						end
// 					end
// 					5'b10001: begin
// 						if( inp ) begin
// 							state <= 5'b00011;
// 							outp <= 011;
// 						end
// 						else begin
// 							state <= 5'b00010;
// 							outp <= 010;
// 						end
// 					end
// 					5'b10010: begin
// 						if( inp ) begin
// 							state <= 5'b00100;
// 							outp <= 100;
// 						end
// 						else begin
// 							state <= 5'b00011;
// 							outp <= 011;
// 						end
// 					end
// 					5'b10011: begin
// 						if( inp ) begin
// 							state <= 5'b00000;
// 							outp <= 000;
// 						end
// 						else begin
// 							state <= 5'b00100;
// 							outp <= 100;
// 						end
// 					end
// 				endcase
// 			end
// 	end
// endmodule


// // test bench for mealy lsb
// module testmealylsb;
//   reg clk, x, reset;				// initialize parameters
//   wire [2:0] z;
//   mealylsb mm (clk,reset, x, z);    // call the object
//   initial
//     begin
//       $dumpfile("lsb_mealy.vcd");
//       $dumpvars(0,lsb_mealy);
//       clk=1'b0; reset=1'b1;
//       #15 reset=1'b0;
//     end
//   always #5 clk= ~clk;
//   initial
//     begin
//       #12 x=1; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 x=0; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 $finish;
//     end
// endmodule




// // test bench for mealymsb

// module testmealymsb;
//   reg clk, x, reset;							// initialize parameters
//   wire [3:0] z;
//   mealymsb mm (clk,reset,x,z);				  // call the object
//   initial
//     begin
//       $dumpfile("msb_mealy.vcd");
//       $dumpvars(0,msb_mealy);
//       clk=1'b0; reset=1'b1;
//       #15 reset=1'b0;
//     end
//   always #5 clk= ~clk;
//   initial
//     begin
//       #12 x=1; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 x=0; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 $finish;
//     end
// endmodule



// // test bench for moore

// module testmooremsb;
//   reg clk, x, reset;
//   wire [0:0] z;									// initialize parameters
//   mooremsb mm (z,x,reset,clk);				  // call the object
//   initial
//     begin
//       $dumpfile("msb_moore.vcd");
//       $dumpvars(0,msb_moore);
//       clk=1'b0; reset=1'b1;
//       #15 reset=1'b0;
//     end
//   always #5 clk= ~clk;
//   initial
//     begin
//       #12 x=1; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 x=0; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 $finish;
//     end
// endmodule


// // test bench for moore lsb
// module testmoorelsb;	
//   reg clk, x, reset;						// initialize parameters
//   wire [0:0] z;
//   moorelsb mm (clk,reset,x,z);						  // call the object
//   initial
//     begin
//       $dumpfile("lsb_moore.vcd");
//       $dumpvars(0,lsb_moore);
//       clk=1'b0; reset=1'b1;
//       #15 reset=1'b0;
//     end
//   always #5 clk= ~clk;
//   initial
//     begin
//       #12 x=1; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 x=0; #10 x=0; #10 x=1; #10 x=0; #10 x=1;
//       #10 $finish;
//     end
// endmodule




// // note there might be compilation error if file  corresponding dump files are not created in test benches
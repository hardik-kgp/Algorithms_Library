module redidue_mod_5(out, in, rst, clk);
output out;
input in;
input clk, rst;
reg out;
reg[2:0] state;
parameter s0=3'd0, s1=3'd1, s2=3'd2, s3=3'd3, s4 = 3'd4;
always @(posedge clk or negedge rst)
if(rst==0) begin state=s0; out=0; end
else begin
case (state)
s0: if(in==0) begin out=0; state=s0; end
else begin out=1; state=s1; end
s1: if(in==0) begin out=2; state=s2; end
else begin out=3; state=s3; end
s2: if(in==0) begin out=4; state=s4; end
else begin out=0; state=s0; end
s3: if(in==0) begin out=1; state=s1; end
else begin out=2; state=s2; end
s4: if(in==0) begin out=3; state=s3; end
else begin out=4; state = s4; end
default: state=s0;
endcase
end
endmodule
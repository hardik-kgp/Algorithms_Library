#!/bin/bash
 
curr="home/hardik/c++practice"
 
g++ "-std=c++11" "solution.cpp"
for j in {1..9}; do
	./a.out < "input0${j}.txt" >  "output0${j}.txt"
	# ./a.out <  "./${curr}/files/in0${j}.txt" > "./${curr}/files/out0${j}.txt"
done

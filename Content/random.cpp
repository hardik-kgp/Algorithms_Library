// add this line inside main to get random number generator 
mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
// use mrand()%k to generate random numbers between 0 to k-1 (inclusive) !!

#include<bits/stdc++.h> 
using namespace std; 
  
// Define the number of runs for the test data 
// generated 
#define RUN 5 
  
// Define the range of the test data generated 
#define MAX 2
  
// Define the maximum number of array elements 
#define MAXNUM 100000
#define MAXK 1000000000
#define int long long 
int32_t main() 
{ 
    srand(time(NULL)); 

       
        freopen("input01.txt", "w", stdout);
        int NUM = 1 + rand() % MAXNUM;  
        int K = 1 + rand()%MAXK;
        cout<<NUM<<" "<<K<<endl;
        int P = 1 + rand()%MAXK;
        K*=P;
        bitset<64> b(K);
        int V = NUM - 64;
        assert(NUM>64);
        int B = 1 + rand()%V;
        for (int j=1; j<=NUM  - 64 - B; j++){
            cout<<0<<"";
        } 
        cout<<b;
        for(int j = 1;j<=B;j++) cout<<0;
        cout<<endl;
    
  
    // Uncomment the below line to store 
    // the test data in a file 
    //fclose(stdout); 
    return(0); 
} 
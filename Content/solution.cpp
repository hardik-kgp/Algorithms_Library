#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
using namespace std;
const int MAXN = 100001;

int main()
{      
    int n,k;
    cin >> n >> k;
    string s;
    cin>>s;
    int res = 0;
    for(int i = 0;i<n;i++){
        res = (res*2 + (s[i] - '0'))%k;
    }
    if(res == 0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}



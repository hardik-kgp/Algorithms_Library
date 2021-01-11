#include <bits/stdc++.h>
using namespace std;
  
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
  
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
  
typedef long long int ll;
  
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =1e9+7;
const ll maxn =5*100001;
ll power(ll x, ll n) {
  ll res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
  }
  return res;
}
int dp[100001][101][2];
int d;
string s;
int solve(int pos,int di,int f,int sum)
{
    if(di>d)
        return 0;
    if(pos==s.length())
    {
        //cout<<sum<<endl;
        if(di==0)
        return 1;
    else
        return 0;
    }
    int &res=dp[pos][di][f];
    if(res!=-1)
        return dp[pos][di][f];
    res=0;
    int fin;
    if(f==0)
    {
        fin=s[pos]-'0';
    }
    else
        fin=9;
   // cout<<fin<<endl;
    for(int x=0;x<=fin;++x)
    {
        int k=f;
        if(f==0 and x<fin)
            k=1;
        res+=solve(pos+1,(sum+x)%d,k,sum+x);
        res=res%mod;
    }
 
    return res%mod;
}
int main()
{
    IOS
    
    
    cin>>s;
    
    cin>>d;
    memset(dp,-1,sizeof(dp));
    int x=solve(0,0,0,0);
    int n=s.length();
    cout<<(x-1+mod)%mod<<endl;
 
}
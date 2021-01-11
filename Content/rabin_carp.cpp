#include<bits/stdc++.h>
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

inline ll pwr(ll x, ll e, ll mod) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e >>= 1;
	}
	return res;
}
const int M = 3e5 + 10, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int P1 = 31, P2 = 37;
ll inv0[M], inv1[M];
void precompute(){
	inv0[M-1] = pwr(P1,mod1-2,mod1);
	inv0[M-1] = pwr(inv0[M-1],M-1,mod1);
	inv1[M-1] = pwr(P2,mod2-2,mod2);
	inv1[M-1] = pwr(inv1[M-1],M-1,mod2);
	for(int  i = M-2;i>=0;i--){
		inv0[i] = (inv0[i+1]*P1)%mod1;
			inv1[i] = (inv1[i+1]*P2)%mod2;
	}
}
pair<vector<ll>,vector<ll>> hsh(string &t) {
	
  int m = t.length();
  vector<ll> h0(m+5,0),h1(m+5,0);
	h0[0] = t[0];
	h1[0] = t[0];
	ll p1 = P1, p2 = P2;
	for (int i = 1; i < m; ++i) {
		h0[i] = (h0[i - 1] + t[i] * p1) % mod1;
		h1[i] = (h1[i - 1] + t[i] * p2) % mod2;
		p1 = (p1 * P1) % mod1;
		p2 = (p2 * P2) % mod2;
	}
  return {h0,h1};
}
 
pair<int,int> get_hsh(int i1,int l1,vector<ll> &h0,vector<ll> &h1){
  int j1 = i1 + l1 - 1;
	ll a0 = (h0[j1] + (i1 ? mod1 - h0[i1 - 1] : 0)) * inv0[i1];
	ll a1 = (h1[j1] + (i1 ? mod2 - h1[i1 - 1] : 0)) * inv1[i1];
  a0%=mod1;
  a1%=mod2;
  return {a0,a1};
}
int main()
{
   #ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
  #endif
  IOS
  
}
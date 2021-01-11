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
const ll maxn =3*1000001;
const ll BLOCK = 555;
ll power(ll x, ll n) {
    ll res = 1;
    for (; n > 0; n >>= 1) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    }
    return res;
}

bool comp(pair<pll,ll> a,pair<pll,ll> b)
{
    if(a.ff.ff/BLOCK!=b.ff.ff/BLOCK)
        return (a.ff.ff/BLOCK<b.ff.ff/BLOCK);
    else
    {
        return a.ff.ss<b.ff.ss;
    }
    
}
ll a[maxn],cnt[maxn],answer=0;
void add(ll position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(ll position) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
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
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++)
  cin>>a[i];
  
  ll q;
  cin>>q;
  ll ans[q];
  vector<pair<pll,ll>> queries;
  for(ll qq=0;qq<q;qq++)
  {
      ll l,r;
      cin>>l>>r;
      queries.pb(mp(mp(l,r),qq));
  }
  sort(queries.begin(),queries.end(),comp);
  ll currentL=0,currentR=0;
  for(ll i=0;i<q;i++)
  {
      while(currentL<queries[i].ff.ff)
      {
          remove(currentL);
          currentL++;
      }
      while(currentL>queries[i].ff.ff)
      {
          add(currentL-1);
          currentL--;
      }
      while(currentR<queries[i].ff.ss)
      {
          add(currentR+1);
          currentR++;
      }
      while(currentR>queries[i].ff.ss)
      {
          remove(currentR);
          currentR--;
      }
      ans[queries[i].ss]=answer;
  }
  for(ll i=0;i<q;i++)
  {
      cout<<ans[i]<<endl;
  }

}
  

//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;


  #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

  #define ff first
  #define ss second
  #define pb push_back
  #define pf push_front
  #define mp make_pair
  #define in insert
  #define ld long double


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
  const ll MAX_NODES =200001;
  const ll MAX_LOG =50;
  const ll maxn = 100000+10;
  #define endl '\n'
  ll power(ll x, ll n) {
      ll res = 1;
      for (; n > 0; n >>= 1) {
      if (n & 1) res = (res * x) % mod;
      x = (x * x) % mod;
      }
      return res;
  }
  multiset<int> m;
  int k;
  int find1(){
			
	if(m.size()<=1)
		return 1;
	auto maxi = m.rbegin();
	auto mini = maxi;
	mini--;
	if((*maxi)+(*mini)<=k)
		return 1;
	else
	{
		return 0;
	}
			
};
  int main()
  {		
	    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
	int t;
	cin>>t;
	while(t--)
	{
		
		int n;
		cin>>n>>k;
		int a[n+1];
		m.clear();
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
		}
		int j = 3;
		int ans = 2;
		m.in(a[1]);
		m.in(a[2]);
		
		for(int i = 1;i<=n;i++)
		{	
			while(j<=n&&find1()==1)
			{	
				m.insert(a[j]);
				j++;
			}
			ans = max(ans,int(m.size())-1);
			m.erase(m.find(a[i]));
		}
		cout<<ans<<endl;
	}
  
  

}

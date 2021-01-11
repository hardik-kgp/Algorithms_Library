#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
// template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;



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
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =998244353;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll maxn = 3000000+10;
#define endl '\n'
#define int ll
ll power(ll x, ll n) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
	if (n & 1) res = (res * x) % mod;
	x = (x * x) % mod;
	}
	return res;
}

int32_t main()
{   

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif 
    IOS 
    int testcases = 1;
    cin>>testcases;
    for(int test = 1;test<=testcases;test++)
    {
      cout<<"Case #"<<test<<": ";
	  int n,k;
	  cin>>n>>k;
	  
	  const int ALPHA = 26;
    vector<vector<int>> trie;
    trie.emplace_back(ALPHA, -1);
    vector<int> visits(1, 0);
    vector<int> pv(1, -1);
	map<int,int> rm;
	map<int,pair<int,int>> rm1;
	while(n--)
	{
	  string s;
      cin >> s;
      int t = 0;
	  int len = 0;
      for (char c : string(s.begin(), s.end())) {
        int d = (int) (c - 'A');
        if (trie[t][d] == -1) {
          trie[t][d] = (int) trie.size();
          trie.emplace_back(ALPHA, -1);
          visits.push_back(0);
          pv.push_back(t);
        }
        t = trie[t][d];
        visits[t]++;
		rm[t] = ++len;
		rm1[t] = mp(rm[t],d);
      }
	}
	
	int ans = 0;
    for (int i = (int) trie.size() - 1; i >= 0; i--) {
	  while(visits[i]>=k)
	  {
		  	ans+=rm[i];
			int v = i;
			while (v != -1) {
				visits[v] -= k;
				v = pv[v];
			}
	  }
      
    }
    cout << ans << '\n'; 
	  
	  


}
  
    
    
    
   
     
       
    

 
}





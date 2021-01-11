  #include<bits/stdc++.h>
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
  #define endl '\n'
  ll power(ll x, ll n) {
      ll res = 1;
      for (; n > 0; n >>= 1) {
      if (n & 1) res = (res * x) % mod;
      x = (x * x) % mod;
      }
      return res;
  }
  const ll maxn = 100000+10;
  int main()
  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS
    int n,q;
    cin>>n>>q;
    set<pii> s;
    s.in({0,n});
    int ans = n;
    while(q--)
    {   
      int k,l,r;
      cin>>l>>r>>k;
      l--;
      while(true){
          auto it=s.lower_bound({l,-1});
          if(it==s.end())
            break;
          pii p=*it;
          if(p.ff>=r)
            break;
          s.erase(it);
          ans-=p.ss-p.ff;
          if(p.ss>r){
              s.insert(pii(r,p.ss));
              ans+=p.ss-r;
          }
      }
        auto it=s.lower_bound(pii(l,-1));
        if(it!=s.begin()){
            it--;
            pii p=*it;
            if(p.ss>l){
                s.erase(it);
                ans-=p.ss-p.ff;
                s.insert(pii(p.ff,l));
                ans+=l-p.ff;
            }
            if(p.ss>r){
                s.insert({r,p.ss});
                ans+=p.ss-r;
            }
        }
        if(k == 2)
          {
            s.in({l,r});
            ans+=r-l;
          }
        cout<<ans<<endl;
    }
    
    
    
    

  }
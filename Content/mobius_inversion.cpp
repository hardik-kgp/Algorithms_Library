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
  const ll maxn = 200000+10;
  int main()
  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS
        ll mu[maxn+1],prime[maxn+1];
    for(ll i=0;i<=maxn;i++)
    {
        mu[i]=1;
        prime[i]=1;
    }
    for(ll i=2;i<=maxn;i++)
    {
        if(prime[i])
        {
            for(ll j=i;j<=maxn;j+=i)
            {
                if(j>i)prime[j]=false;
                if(j%(i*i)==0)mu[j]=0;
                mu[j]=-mu[j];
            }
 
        }
    }
    // g(n) = > <d|n f(d) 
    //  ==> f(n) = <d|n (g(d)*(mu(n/d))) 
    
    ll n,k;
    cin>>n>>k;
    ll pw[maxn+1];
    for(ll i=1;i<=maxn;i++)
    {
      pw[i] = power(i,n);
    }
    ll ans[maxn] = {0};
    
    for(ll i=1;i<=k;i++)
    {
      for(ll j=i;j<=k;j+=i)
      {
         ans[j] = (ans[j] + mu[i]*(pw[j/i]-pw[(j/i) - 1])+2*mod)%mod;
      }
    }
    // for(ll i=1 ;i<=k;i++)
    // {
    //   cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    ll fin =0;
    ll now = 0;
    for(ll i=1;i<=k;i++)
    {
      now+=ans[i];
      now%=mod;;
      fin +=(now^i);
      fin%=mod;
    }
    cout<<fin<<endl;  

  }
  
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
#define endl '\n'
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
 
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
const ll MAX_NODES=100005;
const ll MAX_LOG=30;
ll power(ll x,ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
}
vector<ll> g[MAX_NODES];
ll P[MAX_NODES][MAX_LOG] , parent[MAX_NODES],level[MAX_NODES];
 
void preprocess(ll N){
  for(ll i = 1 ; i <= N ; ++i){
      for(ll j = 0 ; (1<<j) < N ; ++j){
          P[i][j] = -1; 
      }
  }
  for(ll i = 1 ; i <= N ; ++i){
      P[i][0] = parent[i] ; 
  }
  for(ll j = 1; (1<<j) < N ; ++j){
      for(ll i = 1 ; i <= N ; ++i){
          if(P[i][j-1] != -1){
              P[i][j] = P[P[i][j-1]][j-1] ; 
          }
      }
  }
} 
ll LCA(ll u , ll v){
    if(level[u] < level[v]){
        swap(u,v) ;     
    }
   ll dist = level[u] - level[v] ; 
    while(dist > 0){
        ll raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1<<raise_by) ; 
    }
 
    if(u == v){
        return u ; 
    }
 
    for(ll j = MAX_LOG-1 ; j >= 0 ; --j){
        if((P[u][j] != -1) and (P[u][j] != P[v][j])){
            u = P[u][j] ; 
            v = P[v][j] ; 
        }
    }
    return parent[u] ; 
}
void dfs(ll u,ll p)
{ 
  parent[u]=p;
  level[u]=level[p]+1;
  for(auto x:g[u])
  {
    if(x!=p)
    { 
      dfs(x,u);
    }
  }
}
void lca_init(int n){
  for(ll i=0;i<=n;i++)
      {
        g[i].clear();
        a[i] = 0;
        level[i] = 0;
        parent[i] = 0;
        for(int j = 0;j<MAX_LOG;j++){
          P[i][j] = -1;
        }
      }     
}
int main()
{    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
    IOS 
    ll t;
    cin>>t;
    
    while(t--)
    {
      ll n;
      cin>>n;
      ll total=0;
      lca_init(n);
      for(ll i=1;i<n;i++)
      {
        ll u,v,c1,c2;
        cin>>u>>v>>c1>>c2;
        g[u].pb(v);
        g[v].pb(u);
        total+=(c1+c2);
      }
      dfs(1,0);
      preprocess(n);
    /*  for(ll i=1;i<=n;i++)
      {
        cout<<i<<" "<<level[i]<<" "<<parent[i]<<" "<<ans[i]<<" "<<ans1[i]<<endl;
      }*/
      ll q;
    cin>>q;
    while(q--)
    {
      ll x,y;
      cin>>x>>y;
      ll z=LCA(x,y);
      ll final=total-ans1[y]-ans[x]+ans1[z]+ans[z];
      cout<<final<<endl;
    }
    }
    
 
}
 
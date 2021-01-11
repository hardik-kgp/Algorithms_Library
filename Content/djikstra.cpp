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
  const ll maxn = 400000+10;
  #define endl '\n'
  ll power(ll x, ll n) {
      ll res = 1;
      for (; n > 0; n >>= 1) {
      if (n & 1) res = (res * x) % mod;
      x = (x * x) % mod;
      }
      return res;
  }
 vector<pair<int,int>> g[maxn];
vector<int> djikstra(ll src,ll n)
{
  priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; 
  vector<ll> dist(n+1, 1e18),vis(n+1,0); 
  pq.push(make_pair(0, src)); 
  dist[src] = 0; 
  while (!pq.empty()) 
  { 
      ll u = pq.top().second; 
      pq.pop(); 
      if(vis[u])
        continue;
      vis[u] = 1;
      for (auto i:g[u]) 
      { 
          ll v = i.first; 
          ll weight = i.second; 
          if (dist[v] > dist[u] + weight) 
          { 
              dist[v] = dist[u] + weight; 
              pq.push(make_pair(dist[v], v)); 
          } 
      } 
  } 
  return dist;
}
  int main()
  {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  IOS
  

  
  

}

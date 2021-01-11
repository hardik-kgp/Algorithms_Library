#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define trace(...) 
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;
const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 5;
#define endl '\n'
#define ld long double
#define int ll
#define all(x)  (x).begin(),(x).end()


struct DSU{
  vector<int>par,sz;
  DSU(int n)
  {
    par.resize(n);
    sz = vector<int>(n,1);
    iota(par.begin(),par.end(),0);
  }
  int find(int x){
      if(x==par[x])
        return x;
      return par[x] = find(par[x]);
  }
  void unite(int a, int b){
      a = find(a);
      b = find(b);
      if(a==b)
        return ;
      if(sz[a]<sz[b])
        swap(a,b);
      par[b] = a;
      sz[a]+=sz[b];
      return ;
  }
};

void dfs (int v, vector<vector<int>> &g, vector<int> &order, vector<bool> &used) {
    used[v] = true;
    for (int i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs (g[v][i], g, order, used);
    order.push_back (v);
}
vector<vector<int>> compress(vector<vector<int>> g){
  int n = g.size();
  vector<vector<int>> gr(n);
  for(int i = 0;i<n;i++){
    for(int j : g[i]) gr[j].push_back(i);
  }
  vector<bool> used(n, false);
  vector<int> order, component;
  for(int i = 0;i<n;i++){
    if(!used[i]) dfs(i, g , order, used);
  }
  used.assign(n, false);
  DSU dsu(n);
  reverse(all(order));
  
  int id = 0;
  vector<int> m(n, 0);
  for (int v: order) {
      if (!used[v]) {
          dfs(v, gr, component, used);
          for(int j = 1;j<component.size();j++){
            dsu.unite(component[j-1],component[j]);
          }
          m[dsu.find(v)] = id++;
          component.clear();
      }
  }
  vector<vector<int>> gd(id);
  for(int i = 0;i<n;i++){
    for(int j: g[i]){
      if(dsu.find(i) != dsu.find(j)) gd[m[dsu.find(i)]].push_back(m[dsu.find(j)]);
    }
  }
  return gd;
}

int32_t main(){

  IOS

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i = 0;i<m;i++){
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
  }

  g = compress(g);

  n = g.size();

  

  vector<int> order;
  vector<bool> used(n, false);

  for(int i = 0;i<n;i++){
    if(!used[i]) dfs(i, g, order, used);    
  }


  for(int i = 1;i<n;i++){
    bool check = false;
    for(int j : g[order[i]]){
      if(j == order[i-1]) check = true;
    }
    if(!check){
      cout << "TIDAK" << endl;
      return 0;
    }
  }

  cout << "YA" << endl;





  



  
    
 
} 
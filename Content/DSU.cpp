#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

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
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  IOS

  








}

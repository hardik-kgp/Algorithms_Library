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
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;

#define int ll
const ll mod =1e18;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll maxn = 1e6+5;
pair<int,int> ans[maxn];
int sz[maxn];
int lev[maxn];
vector<int> g[maxn];
void getsz(int v, int p){
    sz[v] = 1; 
    lev[v] = lev[p]+1;
    for(auto u : g[v])
    if(u != p){
        getsz(u, v);
        sz[v] += sz[u];
    }
    
}
// ques = > https://codeforces.com/contest/1009/problem/F
// implementaion 2 (nlogn)

// vector<int> *vec[maxn];
// int cnt[maxn];
// void dfs(int v, int p, bool keep){
//     int mx = -1, bigChild = -1;
//     for(auto u : g[v])
//        if(u != p && sz[u] > mx)
//            mx = sz[u], bigChild = u;
//     for(auto u : g[v])
//        if(u != p && u != bigChild)
//            dfs(u, v, 0);
//     if(bigChild != -1)
//         dfs(bigChild, v, 1), vec[v] = vec[bigChild],ans[v] = ans[bigChild];
//     else
//         vec[v] = new vector<int> (),ans[v] = mp(1,-lev[v]);
//     vec[v]->push_back(v);
//     cnt[ lev[v] ]++;
//     ans[v] = max(ans[v],mp(cnt[lev[v]],-lev[v]));
//     for(auto u : g[v])
//        if(u != p && u != bigChild)
//            for(auto x : *vec[u]){
//                cnt[ lev[x] ]++;
//                ans[v] = max(ans[v],mp(cnt[lev[x]],-lev[x]));
//                vec[v] -> push_back(x);
//            }
//     if(keep == 0)
//         for(auto u : *vec[v])
//             cnt[ lev[u] ]--;
// }

// implementation 1 (nlog^2n)

// map<int, int> *cnt[maxn];
// void dfs(int v, int p){
//     int mx = -1, bigChild = -1;
//     for(auto u : g[v])
//        if(u != p){
//            dfs(u, v);
//            if(sz[u] > mx)
//                mx = sz[u], bigChild = u;
//        }
//     if(bigChild != -1)
//         cnt[v] = cnt[bigChild],ans[v] = ans[bigChild];
//     else
//         cnt[v] = new map<int, int>(),ans[v] = mp(1,-lev[v]);
//     (*cnt[v])[lev[v]] ++;
//     ans[v] = max(ans[v],mp((*cnt[v])[lev[v]],-lev[v]));
//     for(auto u : g[v])
//        if(u != p && u != bigChild){
//            for(auto x : *cnt[u])
//                (*cnt[v])[x.first] += x.second,ans[v] = max(ans[v],mp((*cnt[v])[x.first],-x.first));
//        }
//     //   cout<<"in dfs "<<v<<endl;
//     // for(auto x:(*cnt[v])){
//     //   cout<<x.first<<" "<<x.second<<", "; 
//     // }
//     // cout<<ans[v]<<" ";
//     // cout<<endl;
// }

int32_t main()
{
   
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  IOS 
  int n;
  cin>>n;
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  lev[0] =  -1;
  getsz(1,0);
  dfs(1,0);
  for(int i = 1;i<=n;i++){
    
    // for(auto x:(*cnt[i])){
    //   cout<<x.first<<" "<<x.second<<", "; 
    // }
    // cout<<endl;
    cout<<-(ans[i].second + lev[i])<<endl;
  }
}

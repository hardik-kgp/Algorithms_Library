#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

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
const ll mod =1e9+7;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll inf = 1e18+123;

const int maxn = 200001;
vector<pair<int,int>>  t[4*maxn];
vector<int> mins[4*maxn];
int en[maxn],ex[maxn],eu[2*maxn+1],level[maxn],a[maxn];
vector<int> g[maxn];
bool comp(pair<int,int> a,pair<int,int> b){
  if(a.first == b.first)
    return a.second<b.second;
  return a.first<b.first;
}
void build(int id,int l,int r,int b[])
{
  if(l>r)
    return ;
  if(l==r)
    {
      t[id].push_back({level[b[l]],a[b[l]]});
      mins[id].push_back(a[b[l]]);
      return ;
    }

  int mid=(l+r)>>1;
  build(2*id,l,mid,b);
  build(2*id+1,mid+1,r,b);
  t[id].resize(t[2*id].size()+t[2*id+1].size());
  merge(t[2*id].begin(),t[2*id].end(),t[2*id+1].begin(),t[2*id+1].end(),t[id].begin());
  int mini = 1e15;
  mins[id].resize(t[id].size());
  for(int i = 0;i<t[id].size();i++){
    mini = min(mini,t[id][i].second);
    mins[id][i] = mini;
  }
}

int counter(int id,int l,int r,int lq,int rq,int val){
	if(l>r||l>rq||lq>r||lq>rq)return 1e15;
	if(lq<=l&&r<=rq){
		int pos = (upper_bound(t[id].begin(),t[id].end(),make_pair(val,1e15),comp)-t[id].begin()-1);
    return mins[id][pos];
	}
	int mid=(l+r)>>1;
	return min(counter(id*2,l,mid,lq,rq,val),counter(id*2+1,mid+1,r,lq,rq,val));
}
int tem = 0;
void dfs(int u,int p,int d){
  en[u] = ++tem;
  eu[tem] = u;
  level[u] = d;
  for(auto v:g[u]){
    if(v!=p){
      dfs(v,u,d+1);
    }
  }
  ex[u] = ++tem;
  eu[tem] = u;
}
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
   IOS
  int n,root;
  cin>>n>>root;
  for(int i = 1;i<=n;i++)
    cin>>a[i];
  for(int i = 1;i<=n-1;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
 
 
  dfs(root,0,0);
  build(1,1,2*n,eu);
  int m;
  cin>>m;
  int last =  0;
  while(m--){
    int p,q;
    cin>>p>>q;
    
    p = (p+last)%n + 1;
    q = (q+last)%n ;
    last = counter(1,1,2*n,en[p],ex[p],level[p]+q);
    cout<<last<<endl;
  }
   
  
} 

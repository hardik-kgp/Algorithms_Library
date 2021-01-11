#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fill(arr,x) memset(arr,x,sizeof(arr))
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mex 200005
#define lgn 18
vector<int> adj[mex];
int in[mex],out[mex],par[mex],sub[mex],heavy[mex],tym = 0;
int dp[mex][lgn],pos[mex],head[mex],curr;
int tree[5*mex];

inline int dfs(int u,int p)
{
    par[u]=dp[u][0]=p;
    in[u]=++tym;
    sub[u]++;
    int max_val=-1;
    for(int i=1;i<lgn;i++) dp[u][i]=dp[dp[u][i-1]][i-1];
    for(int i=0;i<sz(adj[u]);i++){
        int v=adj[u][i];
        if(v==p) continue;
        int x=dfs(v,u);
        if(x>max_val){
            max_val=x;
            heavy[u]=v;
        }
        sub[u]+=x;
    }
    out[u]=tym;
    return sub[u];
}

inline bool check(int u,int v)
{
    return (in[u]<=in[v] && out[u]>=out[v]);
}

inline int lca(int u,int v)
{
    if(check(u,v)) return u;
    if(check(v,u)) return v;
    for(int i=lgn-1;i>=0;i--){
        if(!check(dp[u][i],v)) u=dp[u][i];
    }
    return dp[u][0];
}

inline void decompose(int u,int h)
{
    pos[u]=curr++;
    head[u]=h;
    if(heavy[u]!=-1) decompose(heavy[u],h);
    for(int i=0;i<sz(adj[u]);i++){
        int v=adj[u][i];
        if(v==par[u] || v==heavy[u]) continue;
        decompose(v,v);
    }
}

inline int build(int u,int s,int e,int aux[])
{
    if(s==e){
        tree[u] = aux[s];
        return tree[u];
    }
    int m=(s+e)/2;
    int x = build(2*u+1,s,m,aux);
    int y = build(2*u+2,m+1,e,aux);
    return tree[u] = max(x, y);
}

inline int que(int u,int s,int e,int l,int r)
{
    if(s>r || e<l) return 0;
    if(s>=l && e<=r) return tree[u];
    int m=(s+e)/2;
    return max(que(2*u+1,s,m,l,r),que(2*u+2,m+1,e,l,r));
}


inline void update(int u, int s, int e, int x, int val){
    if(s > x || e < x) return ;
    if(s == e and s == x){
        tree[u] = val;
        return ;
    }
    int m = (s + e)>>1;
    update(2*u + 1, s, m , x, val);
    update(2*u + 2, m + 1 , e, x, val);

    tree[u] = max(tree[2*u+1], tree[2*u + 2]);
}
inline int query(int u,int v,int n)
{
    int x=0;
    while(head[u]!=head[v]){
        x = max(x, que(0,0,n-1,pos[head[v]],pos[v]));
        v = par[head[v]];
    }
    x = max(x, que(0,0,n-1,pos[u],pos[v]));
    return x;
}

int main()
{
  //    #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // #endif  

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q; cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(heavy, -1, sizeof(heavy));
    dfs(0,0);
    decompose(0,0);
    int aux[n];
    for(int i=0;i<n;i++) aux[pos[i]]=arr[i];
    build(0,0,n-1,aux);
  
    int ans=0;
    while(q--){
        // int u,v,l,r;
        // cin>>u>>v>>l>>r;
        // u=1+((u^ans)%n);
        // v=1+((v^ans)%n);
        // u--; v--;
        // int x = lca(u,v);
        // int a = query(x,u,l,r,n),b=query(x,v,l,r,n);
        // if(arr[x]>=l && arr[x]<=r) ans=a+b-1;
        // else ans=a+b;
        // cout<<ans<<endl;

        int ty, s, x;
        cin >> ty >> s >> x;
        if(ty == 1){
            s--;
            update(0, 0, n - 1, pos[s], x);
        }
        else{
            int a = s, b = x;
            a--, b--;
            
            int x = lca(a,b);
            int u = query(x,a,n),v=query(x,b,n);
            cout<<max(u, v)<<endl;
        }
    }
}
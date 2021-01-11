#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll mod =1e9+7;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll maxn = 4000+10;
const int maxk  = 801;
int dp[maxk][maxn];
int opt[maxk][maxn];
int n,k;
int a[maxn][maxn];
int csum[maxn][maxn],up1[maxn];
int cost(int i,int j){
	int ans = up1[j] - up1[i-1];
  ans = ans -csum[i-1][j] + csum[i-1][i-1];
  return ans;
}
void calc_brute(int d,int l,int optl,int optr){
   if(l <1 || l> n)
    return ;
   int ans = 0;
    if(d>l){
      dp[d][l] = 1e9;
      opt[d][l] = optl;
      return ;
    }
    optr = min(optr,l-1);
    for(int i = optr;i>=optl;i--){
      if(cost(i+1,l)+dp[d-1][i]<=dp[d][l]){
        opt[d][l] = i;
        dp[d][l] = cost(i+1,l)+dp[d-1][i];
      }
    }
  
}
void solve(int d, int l,int r, int optl,int optr){
  if(l>r)
    return ;
  if(l==r){
    calc_brute(d,l,optl,optr);
    return ;
  }
  int mid = (l+r)>>1;
  calc_brute(d,mid,optl,optr);
  solve(d,mid+1,r,opt[d][mid],optr);
  solve(d,l,mid-1,optl,opt[d][mid]);

}
int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
  }
   cin>>n>>k;
   for(int i= 1;i<=k;i++){
     for(int j = 1;j<=n;j++)
      dp[i][j] = 1e9;
   }
   for(int i = 1; i<=n; i++){
     for(int j = 1;j<=n;j++){
       			char c = '#';
            while(!isdigit(c))
              c = getchar();
            a[i][j] = c-'0';
     }
   }
   
   for(int i = 1;i<=n;i++){
     for(int j = 1;j<=n;j++){
       csum[i][j] = csum[i-1][j] + csum[i][j-1] -csum[i-1][j-1] + a[i][j];
     }
   }
  for(int j = 1;j<=n;j++){
     for(int i = 1;i<=j;i++){
       a[i][j]+=a[i-1][j];
     }
     up1[j] =up1[j-1]+ a[j][j];
   }
   for(int i = 1;i<=n;i++){
        dp[1][i]  = cost(1,i);
   }

  for(int  i = 2;i<=k;i++){
    solve(i,1,n,1,n);
  }
  printf("%d",dp[k][n]);

   
}

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
const ll MAXN=300001;
const ll LOGMAXN=30;
ll power(ll x, ll n) {
      ll res = 1;
      for (; n > 0; n >>= 1) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
      }
      return res;
    }
ll gcd_table[MAXN][LOGMAXN];
ll min_table[MAXN][LOGMAXN];
 void pre_process_gcd(ll A[MAXN], ll N)
{
ll i, j; 
for (i = 0; i < N; i++)
gcd_table[i][0] = A[i];
for (j = 1; 1 << j <= N; j++)
for (i = 0; i + (1 << j) - 1 < N; i++)
    gcd_table[i][j]=__gcd(gcd_table[i][j-1],gcd_table[i+ (1 << (j-1)) ][j-1]);
}
 void pre_process_min(ll A[MAXN], ll N)
{
ll i, j; 
for (i = 0; i < N; i++)
min_table[i][0] = A[i];
for (j = 1; 1 << j <= N; j++)
for (i = 0; i + (1 << j) - 1 < N; i++)
  min_table[i][j]=min(min_table[i][j-1],min_table[i+(1LL<<(j-1))][j-1]);
  
}
ll query_min(ll L, ll R) //0 based indexing and closed interval [l,r]
{ 
    
    ll j = (ll)log2(R - L + 1); 
    return min(min_table[L][j] ,min_table[R - (1 << j) + 1][j]); 
} 
ll query_gcd(ll L, ll R) 
{ 
    
    ll j = (ll)log2(R - L + 1); 

    return __gcd(gcd_table[L][j] ,gcd_table[R - (1 << j) + 1][j]); 
        
}

int main()
{ 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
    ll n;
    cin>>n;
    ll a[MAXN];
    for(ll i=0;i<n;i++)
      cin>>a[i];
    pre_process_min(a,n);
    pre_process_gcd(a,n);
    
      


}
  











// Incase you need a struct

// struct sparse_table{
//   vector<int> A;
//   vector<vector<int>> table;
//   int log = 0, n;
//   void build(){
//     for (int i = 0; i < n; i++)
//     table[i][0] = A[i];
//     for (int j = 1; (1 << j) <= n; j++)
//       for (int i = 0; i + (1 << j) - 1 < n; i++)
//         table[i][j]=min(table[i][j-1],table[i+(1LL<<(j-1))][j-1]);
//   }
//   sparse_table(){}
//   sparse_table(vector<int> _A){
//     A = _A;
//     n = A.size();
//     while((1ll<<log)<=(n)){
//       log++;
//     }
//     table = vector<vector<int>>(n+2,vector<int>(log+1,0));
//     build();
//   }

//   int query(int L, int R) //0 based indexing and closed interval [l,r]
//   {       
//       if(R<L || L<0 || R>n) return mod;
//       int j = (int)log2(R - L + 1); 
//       return min(table[L][j] ,table[R - (1 << j) + 1][j]); 
//   } 

// };
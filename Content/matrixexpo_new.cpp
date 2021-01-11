#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
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
const int maxn = 100005;
#define endl '\n'
#define int ll
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7; 
ll sum(ll x, ll y)
{
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
struct Matrix
{
	vector<vector<ll>> a;
  int N;
 
	Matrix(ll _N,int I = 0)
	{	
    N = _N;
		a.resize(N,vector<ll>(N,0));
    if(I){
      for(int i = 0;i<N;i++)
        a[i][i] = 1;
    }
	}
 
	
};
void multiply(Matrix &A,Matrix &B)  // updates A to A*B
	{ 
    int N = A.a.size();
		Matrix res(N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				res.a[i][j] = 0;
				for (int h = 0; h < N; h++)
				{
					res.a[i][j] = sum(res.a[i][j], mult(A.a[i][h], B.a[h][j]));
				}
			}
		A = res;
		return;
}
void bin_pow(Matrix &M, ll n)
{	  
  Matrix res(M.a.size(),1);
  while(n){
    if(n%2){
      multiply(res,M);
    }
    n/=2;
    multiply(M,M);
  }
  M = res;
}
int32_t main()
{ 
  IOS
   #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> a;
  for(int i = 1;i<=n;i++){
    int l,r,b;
    cin>>b>>l>>r;
    a.emplace_back(l,-b);
    a.emplace_back(r,b);
  }
  sort(all(a));
  Matrix A(3);
  A.a = {{1,1,0},{1,1,1},{0,1,1}};
  Matrix res(3,1),C = A;
  int current = 1;
  int cnt[3] = {0};
  for(int i = 0;i<a.size();i++){
    if(a[i].second < 0){
      Matrix B = A;
      bin_pow(B,a[i].first - current - 1);
      
      multiply(B,res);
      res = B;
      cnt[-a[i].second-1]++;
      for(int k = 0;k<3;k++)
      for(int j = 0;j<3;j++){
        if(cnt[k] > 0)
          A.a[k][j] = 0;
        else 
          A.a[k][j] = C.a[k][j];
      }
      current = a[i].first-1;
    }
    else{
      Matrix B = A;
      bin_pow(B,a[i].first - current);
      multiply(B,res);
      res = B;
            cnt[a[i].second-1]--;
      for(int k = 0;k<3;k++)
      for(int j = 0;j<3;j++){
        if(cnt[k] > 0)
          A.a[k][j] = 0;
        else 
          A.a[k][j] = C.a[k][j];
      }
      current = a[i].first;
    }
  }
      Matrix B = A;
      bin_pow(B,m - current);
      multiply(B,res);
      res = B;
      cout<<res.a[1][1]<<endl;
  

  

}
 
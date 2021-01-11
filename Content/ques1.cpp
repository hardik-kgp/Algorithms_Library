//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
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
const ll mod =1e9+7;
const int maxn = 100005;
#define endl '\n'
#define int ll
#define ld long double
#define all(x) (x).begin(),(x).end()

struct FT {
	vector<ll> s;
	FT(int n) : s(n,0) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < (s).size(); pos |= pos + 1) s[pos] = (s[pos]+dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = (res+s[pos-1]);
		return res;
	}
};
FT ft1(100005), ft2(100005);

void update(int l, int r, int v){
  ft1.update(l, v);
  ft1.update(r+1, -v);
}
void update1(int l,int r, int v){
  ft2.update(l, v);
  ft2.update(r + 1, -v);
}

int query(int i){
  return ft1.query(i+1) ;
}
int query1(int i){
  return ft2.query(i+1);
}

int32_t main()
{ 
   
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n, m, k;
  cin >> n >> m >> k;
  int x[k+1], y[k+1], xd[k+1], yd[k+1];
  for(int i = 1;i<=k;i++){
    cin >> x[i] >> y[i] >> xd[i] >> yd[i];
    if(x[i] > xd[i]) swap(x[i], xd[i]);
    if(y[i] > yd[i]) swap(y[i], yd[i]);
  }

  for(int i = 1;i<=k;i++){
    update( y[i], yd[i], 2*(yd[i] - y[i]) + xd[i] - x[i]);
    int j = max(1ll, y[i] - (xd[i] - x[i] + 1)/2);
    if(j < y[i]){
      update( j, y[i] -1, xd[i] - x[i] + (y[i] + yd[i]));
      update1( j, y[i]-1, -2);
      update( 1, j - 1, 2*(xd[i] - x[i]) + 2*(yd[i] - y[i]));
    }
    else{
      update( 1, y[i] - 1, 2*(xd[i] - x[i]) + 2*(yd[i] - y[i]));
    }


    j = min(m , (xd[i] - x[i])/2 - yd[i]);
    
    if(j>yd[i]){
      update( yd[i] + 1, j, (xd[i] - x[i]) - y[i] - yd[i]);
      update1( yd[i]+1, j , +2);
      update( j + 1, m , 2*(xd[i] - x[i]) + 2*(yd[i] - y[i]));
    }
    else{
      update( yd[i]+1, m, 2*(xd[i] - x[i]) + 2*(yd[i] - y[i]));
    }
  }
  int ans = 1e18;
  for(int i = 1;i<=m;i++){
    int here = query(i) + i*(query1( i));
    ans = min(ans,  here);
  }

  cout << ans << endl;


  
  
}
 
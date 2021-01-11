//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
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
#define trace(...) 
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;
const ll mod =1e9+7;
const int maxn = 2000005;
#define endl '\n'
#define int ll
#define ld long double
#define all(x) (x).begin(),(x).end()

int32_t main()
{ 
  IOS
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector<vector<int>> res;
    int ans = 1;
    for(int i = 0;i<n;i++){
      if(a[i]<b[i]) ans = 0;
    }
    for(int j = 25;j>=0;j--){
      char c = 'a'+ j;
      bool check = false;
      int found = -1;
      vector<int> v;
      for(int i = 0;i<n;i++){
        if(b[i] == c and a[i] != c){
          check = true;
          v.push_back(i);
        }
        if(a[i] == c) found= i;
      }
      if(check){
        if(found == -1){
          ans = 0;
          break;
        } 
        v.push_back(found);
        res.push_back(v);
        for(int i = 0;i<v.size();i++) a[v[i]] = c;
        
      }
    }
    if(!ans) cout<<-1<<endl;
    else{
      cout<<res.size()<<endl;
      for(auto v:res){
        cout<<v.size()<<" ";
        for(auto x:v)
          cout<<x<<" ";
        cout<<endl;
      }
    }
  }
  
  

}
 
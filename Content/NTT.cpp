#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define in insert



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

const int MOD = 1009;
#define M_PI acos(-1)
//use mul(vector<int> a,vector<int> b) to multiply two polynomials a and b
//the higher power coefficients have the higher index in the vectors
//the mul function will return a vector of long long
//If mod is different just change the above predefined mod
 
namespace FFT // taken from https://www.codechef.com/viewsolution/11939789
{
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long double ld;
struct base
{
    typedef long double T;
    T re, im;
    base() :re(0), im(0) {}
    base(T re) :re(re), im(0) {}
    base(T re, T im) :re(re), im(im) {}
    base operator + (const base& o) const
    {
        return base(re + o.re, im + o.im);
    }
    base operator - (const base& o) const
    {
        return base(re - o.re, im - o.im);
    }
    base operator * (const base& o) const
    {
        return base(re * o.re - im * o.im, re * o.im + im * o.re);
    }
    base operator * (ld k) const
    {
        return base(re * k, im * k) ;
    }
    base conj() const
    {
        return base(re, -im);
    }
};
const int N = 20;
const int MAXN = (1<<N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];
void build_rev(int k)
{
    static int rk = -1;
    if( k == rk )return ;
    rk = k;
    fore(i, 1, (1<<k) )
    {
        int j = rev[i-1], t = k-1;
        while( t >= 0 && ((j>>t)&1) )
        {
            j ^= 1 << t;
            --t;
        }
        if( t >= 0 )
        {
            j ^= 1 << t;
            --t;
        }
        rev[i] = j;
    }
}
void fft(base *a, int k)
{
    build_rev(k);
    int n = 1 << k;
    forn(i, n) if( rev[i] > i ) swap(a[i], a[rev[i]]);
    for(int l = 2, lll = 1; l <= n; l += l, lll += lll)
    {
        if( w[lll].re == 0 && w[lll].im == 0 )
        {
            ld angle = M_PI / lll;
            base ww( cosl(angle), sinl(angle) );
            if( lll > 1 ) for(int j = 0; j < lll; ++j)
                {
                    if( j & 1 ) w[lll + j] = w[(lll+j)/2] * ww;
                    else w[lll + j] = w[(lll+j)/2];
                }
            else w[lll] = base(1, 0);
        }
        for(int i = 0; i < n; i += l) forn(j, lll)
        {
            base v = a[i + j], u = a[i + j + lll] * w[lll + j];
            a[i + j] = v + u;
            a[i + j + lll] = v - u;
        }
    }
}
vector<int> mul(const vector<int>& a, const vector<int>& b)
{
    int k = 1;
    while( (1<<k) < (a.size() + b.size()) ) ++k;
    int n = (1<<k);
    forn(i, n) f1[i] = base(0,0);
    forn(i, a.size()) f1[i] = f1[i] + base(a[i], 0);
    forn(i, b.size()) f1[i] = f1[i] + base(0, b[i]);
    fft(f1, k);
    forn(i, 1 + n/2)
    {
        base p = f1[i] + f1[(n-i)%n].conj();
        base _q = f1[(n-i)%n] - f1[i].conj();
        base q(_q.im, _q.re);
        f1[i] = (p * q) * 0.25;
        if( i > 0 ) f1[(n - i)] = f1[i].conj();
    }
    forn(i, n) f1[i] = f1[i].conj();
    fft(f1, k);
    vector<int> r(a.size() + b.size());
    forn(i, r.size() )
    {
        r[i] = ll (f1[i].re / n + 0.5) % MOD;
    }
    return r;
}
}



vector<vector<int>> v;
vector<int> solve(int l, int r){
  if(l == r)
    return v[l];
  int mid = (l+r)>>1;
  vector<int> a = solve(l,mid);
  vector<int> b = solve(mid+1,r);
  return FFT::mul(a,b);
}
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
   IOS
   
   int n,m,k;
   cin>>n>>m>>k;

   vector<int> cnt(200002,0);
   for(int i = 0;i<n;i++){
     int c;
     cin>>c;
     cnt[c]++;
   }
   sort(cnt.begin(),cnt.end(),greater<int>());
   
   vector<int> v1;
   for(int  i  = 0;cnt[i];i++){
     v1.push_back(cnt[i]);
   }
   sort(v1.begin(),v1.end());
   for(int i = 0;i<v1.size();i++)
    v.emplace_back(v1[i]+1,1);
   vector<int> ans = solve(0,v.size()-1);
   if(ans.size()>k)
    cout<<ans[k]<<endl;
  else
  {
    cout<<0<<endl;
  }
  
   
   
   

  
  
  

  
} 
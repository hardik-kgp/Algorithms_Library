#include<bits/stdc++.h>
using namespace std;
 
typedef long double dbl;
typedef  long long ll;
#define pw(x) (1LL << (x))
#define forn(i, n) for (int i = 0; i < (n); i++)
 
namespace fft
 
{
    const int maxBase = 18;
    const int maxN = 1 << maxBase;
 
    struct num
    {
        dbl x, y;
        num(){}
        num(dbl xx, dbl yy): x(xx), y(yy) {}
        num(dbl alp): x(cos(alp)), y(sin(alp)) {}
    };
 
    inline num operator + (num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator - (num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator * (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }
 
    const dbl PI = acos(-1);
 
    num root[maxN];
    int rev[maxN];
    bool rootsPrepared = false;
 
    void prepRoots()
    {
        if (rootsPrepared) return;
        rootsPrepared = true;
        root[1] = num(1, 0);
        for (int k = 1; k < maxBase; ++k)
        {
            num x(2 * PI / pw(k + 1));
            for (int i = pw(k - 1); i < pw(k); ++i)
            {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * x;
            }
        }
    }
 
    int base, N;
 
    int lastRevN = -1;
    void prepRev()
    {
        if (lastRevN == N) return;
        lastRevN = N;
        forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
    }
 
    void fft(num *a, num *f)
    {
        forn(i, N) f[i] = a[rev[i]];
        for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) forn(j, k)
        {
            num z = f[i + j + k] * root[j + k];
            f[i + j + k] = f[i + j] - z;
            f[i + j] = f[i + j] + z;
        }
    }
 
    num a[maxN], b[maxN], f[maxN], g[maxN];
    ll A[maxN], B[maxN], C[maxN];
 
    void _multMod(int mod, bool eq)
    {
        forn(i, N)
        {
            int x = A[i] % mod;
            a[i] = num(x & (pw(15) - 1), x >> 15);
        }
        forn(i, N)
        {
            int x = B[i] % mod;
            b[i] = num(x & (pw(15) - 1), x >> 15);
        }
        fft(a, f);
        if (!eq) {
            fft(b, g);
        } else {
            for (int i = 0; i < N; i++) g[i] = f[i];
        }
 
        forn(i, N)
        {
            int j = (N - i) & (N - 1);
            num a1 = (f[i] + conj(f[j])) * num(0.5, 0);
            num a2 = (f[i] - conj(f[j])) * num(0, -0.5);
            num b1 = (g[i] + conj(g[j])) * num(0.5 / N, 0);
            num b2 = (g[i] - conj(g[j])) * num(0, -0.5 / N);
            a[j] = a1 * b1 + a2 * b2 * num(0, 1);
            b[j] = a1 * b2 + a2 * b1;
        }
 
        fft(a, f);
        fft(b, g);
 
        forn(i, N)
        {
            ll aa = f[i].x + 0.5;
            ll bb = g[i].x + 0.5;
            ll cc = f[i].y + 0.5;
            C[i] = (aa + bb % mod * pw(15) + cc % mod * pw(30)) % mod;
        }
    }
 
    void prepAB(int n1, int n2)
    {
        base = 1;
        N = 2;
        while (N < n1 + n2) base++, N <<= 1;
 
        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;
 
        prepRoots();
        prepRev();
    }
 
 
    void mult(int n1, int n2, int mod, bool eq)
    {
        prepAB(n1, n2);
        _multMod(mod, eq);
    }
 
    // HOW TO USE ::
    // -- set correct maxBase
    // -- use mult(n1, n2), multMod(n1, n2, mod) and multLL(n1, n2)
    // -- input  : A[], B[]
    // -- output : C[]
}
 
const int MX = (1<<17);
 
ll p2[MX] , fact[MX] , invfact[MX];
 
int n , arr[MX];
 
int MOD = 1e9 + 7;
 
ll POW(ll x , ll y){
    if(y == 0) return 1;
    ll ret = POW(x , y/2);
    ret *= ret; ret %= MOD;
    if(y % 2) ret *= x;
    return ret % MOD;
}
 
 
int main(){
        #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin>>T;
 
    p2[0] = fact[0] = 1;
    for(int j = 1 ; j < MX ; j++){
        p2[j] = 2 * p2[j-1]; p2[j] %= MOD;
        fact[j] = j * fact[j-1]; fact[j] %= MOD;
    }
    for(int j = 0 ; j < MX ; j++)
        invfact[j] = POW(fact[j] , MOD - 2);
 
    while(T--){
 
        scanf("%d",&n);
 
        for(int j = 1 ; j <= n ; j++){
            scanf("%d",&arr[j]);
        }
        
        //sort(arr+1,arr+1+n);
 
        for(int i = 0 ; i < MX ; i++){
            fft::A[i] = 0;
            fft::B[i] = 0;
        }
 
        for(int j = 1 ; j <= n ; j++){
            fft::A[j] = 1ll * (((1ll *  p2[n - j] * fact[j - 1])%MOD) * arr[j])%MOD;
        }
 
        for(int j = 0 ; j <= n ; j++){
            fft::B[j] = invfact[n - j];
        }
 
        fft::mult(n + 2 , n + 2 , MOD , 0);
 
        for(int j = 1 ; j <= n ; j++){
            ll theta = fft::C[n + j];
            theta *= invfact[j-1];
            theta %= MOD;
            printf("%lld ",theta);
        }
        puts("");
    }
 
}
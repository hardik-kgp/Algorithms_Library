const ll md = (ll) 1e9 + 7;
 
inline ll add(ll a, ll b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}
 
inline ll sub(ll a, ll b) {
  a -= b;
  if (a < 0) a += md;
  return a;
}
 
inline ll mul(ll a, ll b) {
  return (ll) ((long long)((a%md) * (b%md)) % md);
}
 
inline ll power(ll a, long long b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
 
inline ll inv(ll a) {
  a %= md;
  if (a < 0) a += md;
  ll b = md, u = 0, v = 1;
  while (a) {
    ll t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

vector<int> fact(maxn+5);
void init (int n)
{
  fact[0] = 1;
  for(int i = 1;i<=n;i++)
  {
    fact[i] = mul(i,fact[i-1]);
  }
}
int nck(int n,int k)
{
  return mul(fact[n],mul(inv(fact[k]),inv(fact[n-k])));
}

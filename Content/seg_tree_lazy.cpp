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
const ll maxn=1e6+7;
ll t[4*maxn+5];
ll lazy[4*maxn+5];
 
void push(ll id,ll l,ll r){
  
    t[id]+=(r-l+1)*lazy[id];
    if(l!=r){
      lazy[id<<1]+=lazy[id];
      lazy[id<<1|1]+=lazy[id];
    }
    lazy[id]=0;
  
}
 
void build(ll id,ll l,ll r,ll b[]){
  if(l==r){
    t[id]=b[l];
    lazy[id]=0;
    return;
  }
  ll mid=(l+r)>>1;
  build(id<<1,l,mid,b);
  build(id<<1|1,mid+1,r,b);
  t[id]=t[id<<1]+t[id<<1|1];
  lazy[id] = 0;
}
 
void update(ll id,ll l,ll r,ll lq,ll rq,ll val){
  push(id,l,r);
  if(l>r||lq>r||l>rq)return;
  if(lq<=l&&r<=rq){
    lazy[id]+=val;
    push(id,l,r);
    return;
  }
  ll mid=(l+r)>>1;
  update(id<<1,l,mid,lq,rq,val);
  update(id<<1|1,mid+1,r,lq,rq,val);
  t[id]=t[id<<1]+t[id<<1|1];
}
 
ll counter(ll id,ll l,ll r,ll lq,ll rq){
  push(id,l,r);
  if(l>r||lq>r||l>rq)return 0;
  if(lq<=l&&r<=rq){
    return t[id];
  }
  ll mid=(l+r)>>1;
  return counter(id<<1,l,mid,lq,rq)+counter(id<<1|1,mid+1,r,lq,rq);
}
int main()
{ 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
   IOS
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,q;
       cin>>n>>q;
       ll a[n+1];
       memset(a,0,sizeof(a));
       memset(::t,0,sizeof(::t));
       memset(lazy,0,sizeof(lazy));
       build(1,1,n,a);
       while(q--){
           ll c;
           cin>>c;
           if(c==0)
           {
               ll p,q,v;
               cin>>p>>q>>v;
                update(1,1,n,p,q,v);
           }
           else
           {
            ll p,q;
            cin>>p>>q;
               cout<<counter(1,1,n,p,q)<<endl;
           }
           
       }
   }
   
}

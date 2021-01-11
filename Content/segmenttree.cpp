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
const ll mod =998244353;

const int maxn = 200001;
int t[4*maxn];
void build(int id,int l,int r,int b[])
{
  if(l>r)
    return ;
  if(l==r)
    {
      t[id]=b[l];
      return ;
    }

  int mid=(l+r)>>1;
  build(2*id,l,mid,b);
  build(2*id+1,mid+1,r,b);
  t[id]= t[2*id]+t[2*id+1];
}

 
void update(int id,int l,int r,int pos,int val){
	if(pos>r||pos<l||l>r)return;
	if(l==r&&l==pos){
		t[id]=val;
		return;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	t[id]=t[id*2]+t[id*2+1];
}
int kth(int id,int l,int r,int k){
	if(l==r&&k!=t[id])return -1;
	else if(l==r)return l;
	int mid=(l+r)>>1;
	if(k<=t[id*2])return kth(id*2,l,mid,k);
	else return kth(id*2+1,mid+1,r,k-t[id*2]);
}
int query(int id,int l,int r,int lq,int rq){
	if(l>r||l>rq||lq>r||lq>rq)return 0;
	if(lq<=l&&r<=rq){
		return t[id];
	}
	int mid=(l+r)>>1;
	return query(id*2,l,mid,lq,rq)+query(id*2+1,mid+1,r,lq,rq);
}
int main()
{
	  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	IOS

    ll n;
	cin>>n;
	int a[n+1];
	for(ll i=0;i<n;i++)
	{	
		cin>>a[i+1];

	}
	build(1,1,n,a);
	for(int i = 1;i<=6;i++)
		cout<<t[i]<<" ";
	// ll q;
	// cin>>q;
	// while(q--)
	// {
	// 	ll l,r;
	// 	cin>>l>>r;
	// 	cout<<counter(1,1,n,l,r)<<endl;
	// }



}
    
 
    
    


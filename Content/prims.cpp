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
const int maxn=200001;
double x[1000],y[1000];
ll n=1000;
double dist(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

vector<pair<int,double> > g[1000];

double prim()
{	
	double key[n+1];
	bool mst[n+1]={0};

	priority_queue< pair<double,int> ,vector< pair<double,int > >, greater < pair<double,int> > >  pq;
	int parent[n+1];
	for(ll i=1;i<=n;i++)
	{
		key[i]=100000000000.000;
		mst[i]=false;
		parent[i]=-1;
	}

	key[1]=0.0;

	pq.push({key[1],1});
	while(!pq.empty())
	{
		ll u=pq.top().ss;
		pq.pop();
		mst[u]=true;	
		for(auto x:g[u])
		{
			ll v=x.ff;
			double w=x.ss;

			if(key[v]>w&&mst[v]==false)
			{
				parent[v]=u;
				key[v]=w;
				pq.push({key[v],v});
			}
		}	


	}


	double sum=0.0;
for(ll i=2;i<=n;i++)
{
	sum+=(dist(i,parent[i]));
}


return sum;

}

int main()
{		
	
   /* #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/
    IOS
    cin>>n;

    for(ll i=1;i<=n;i++)
    {
    	cin>>x[i];
    	cin>>y[i];
    }


    for(ll i=1;i<=n;i++)
    {
    	for(ll j=i+1;j<=n;j++)
    	{
    		
    		g[i].pb({j,dist(i,j)});
    		g[j].pb({i,dist(i,j)});
    	
    	}
    }


    cout<<setprecision(9)<<fixed;
    cout<<prim();




}
    
 
    
 
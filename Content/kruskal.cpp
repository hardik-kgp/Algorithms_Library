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
int n=1000;
double dist(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int par[1000];
int size[1000];


vector<tuple<int,int,double>>  ed;



int fi(int i)
{
	if(par[i]==i)
		return i;
	else
		return par[i]=fi(par[i]);
}

void un(int x,int y)
{
	x=fi(x);
	y=fi(y);

	if(size[x]<size[y])
		par[x]=y,size[y]+=(size[x]);
	else
		par[y]=x,size[x]+=size[y];

	return ;
}


bool comp(tuple<int,int,double> a,tuple<int,int,double> b)
	{return get<2>(a) < get<2>(b);}

double kruskal(int k)
{	

	sort(ed.begin(),ed.end(),comp);

	int u,v;
	double w;
	vector<double> ans;
	for(int i=0;i<ed.size();i++)
	{
		tie(u,v,w)=ed[i];
		/*cout<<u<<" "<<v<<" "<<w<<endl;

		cout<<fi(u)<<" "<<fi(v)<<endl;*/
		if(fi(u)!=fi(v))
		{	
			ans.pb(w);
			
			un(u,v);
		}

	}
	
	sort(ans.begin(),ans.end());

/*	for(auto x:ans)
		cout<<x<<" ";*/




	return ans[ans.size()-k+1];

}

int main()
{		
	
 /*   #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/
    IOS
    cin>>n;

    for(int i=1;i<=n;i++)
    {
    	cin>>x[i];
    	cin>>y[i];
    }


    for(int i=1;i<=n;i++)
    {	
    	par[i]=i;
    	size[i]=1;
    	for(int j=i+1;j<=n;j++)
    	{
    		ed.pb(make_tuple(i,j,dist(i,j)));
    	
    	}
    }
    int k;

    cin>>k;

    cout<<setprecision(9)<<fixed;
    cout<<kruskal(k);




}
    
 
    
 
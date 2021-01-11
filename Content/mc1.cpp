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


int main()
{
	  int t;
	  cin>>t;
	  while(t--)
	  {	
	  	int n,k,ans1=0;
	  	cin>>n>>k;
	  	int a[n+1];

	  	for(int i=0;i<n;i++)
	  	{
	  		cin>>a[i];
	  	}

	  	
	  	for(int i=0;i<n;i++)
	  	{
	  		for(int j=i;j<n;j++)
	  		{	
	  
	  			int l=j-i+1;
	  			int h=(k/l)+1-(k%l==0);

	  			
	  			sort(a+i,a+j+1);


	  			int temp=a[i+k/h-(k%h==0)];
	  			int count=0;
	  			//cout<<"temp"<<temp<<endl;

	  			for(int m=i;m<=j;m++)
	  			{
	  				if(a[m]==temp)
	  					count++;
	  			}
	  			int ans=0;

	  			for(int m=i;m<=j;m++)
	  			{
	  				if(a[m]==count)
	  					{
	  						ans++;
	  						break;
	  					}
	  			}

	  			if(ans!=0)
	  			{
	  				ans1++;
	  			}

	  		}
	  	}

	  	cout<<ans1<<endl;
	  }
}
    
 
    
    

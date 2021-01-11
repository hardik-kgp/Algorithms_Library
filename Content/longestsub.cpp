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
   /*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/
    ll i,j,n,m;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    }

    
    cin>>m;
    ll b[m];

    for(i=0;i<m;i++)
    {
    	cin>>b[i];
    }

    ll v;
    cin>>v;
    ll c[v];
    
    for(i=0;i<v;i++)
    {
    	cin>>c[i];
    }

    ll dp[n+1][m+1][v+1];

    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=m;j++)
    	{
    		for(int k=0;k<=v;k++)
    		{
    			if(i==0||j==0||k==0)
    				dp[i][j][k]=0;
    			else if(a[i-1]==b[j-1]&&a[i-1]==c[k-1])
    				dp[i][j][k]=dp[i-1][j-1][k-1]+1;
    			else
    			{
    				dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
    			}

    		}

    	}
    }

    cout<<dp[n][m][v];

    return 0;


}
    
 
    
    


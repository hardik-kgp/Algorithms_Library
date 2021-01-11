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
/*const ll mod =1e9+7;
ll power(ll x,ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % mod; 
    p = (p * p) % mod; 
  
    return (y%2 == 0)? p : (x * p) % mod; 
}*/
vector<pair<ll,char>> g[10001];
pair<ll,char> root;
void constructtrie(vector<string> s)
{
  ll n=s.size();
  ll last=0;
  for(ll i=0;i<n;i++)
  { 
    pair<ll,char> currnode=root;
    string p=s[i];
    for(ll j=0;j<p.size();j++)
    {
      char currsymbol=p[j];
      bool found=0;
      for(auto x:g[currnode.ff])
      {
        if(x.ss==currsymbol)
        {
          currnode=x;
          found=1;
          break;
        }
      }

      if(!found)
      {
        pair<ll,char> x={++last,p[j]};
        g[currnode.ff].pb(x);
        currnode=x;
      }


    }
  }
}

void showedges(ll u,ll p)
{
    for(auto x:g[u])
    {
      if(x.ff!=p)
      {
          cout<<u<<"->"<<x.ff<<":"<<x.ss<<endl;
          showedges(x.ff,u);
      }
    }
}
int main()
{
  /*
     #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif */
     IOS
     ll n;
     root={0,'!'};
     cin>>n;
     vector<string> s(n);
     for(ll i=0;i<n;i++)
      cin>>s[i];

    constructtrie(s);
    showedges(0,-1);




}
    
 
    
    
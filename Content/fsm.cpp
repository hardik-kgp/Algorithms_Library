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

enum dir{down,up,idle};

class liftop
{
private:
	int tot,curr,inc,oc,i,temp;
		set<int> m,g1,g2,ans;
	string g; 
	enum dir state;
	enum dir first;

public:
	void moveup(int init,int fin)
	 {
	 	for(i=init;i<=fin;i++)
	   	{
	   		if(m.find(i)!=m.end())
	   		{
	   			cout<<i<<"->";
	   		
	   			m.erase(m.find(i));
	   		}

	   		else if(g1.find(i)!=g1.end())
	   		{
	   			cout<<i<<"->";
	   			
	   			g1.erase(g1.find(i));
	   		}
		
		}

	 }


void movedown(int init,int fin)
	 {
	 	for(i=init;i>=fin;i--)
		{
			if(m.find(i)!=m.end())
	   		{
	   			cout<<i<<"->";
	   			ans.insert(i);
	   			m.erase(m.find(i));
	   		}

	   		else if(g2.find(i)!=g2.end())
	   		{
	   			cout<<i<<"->";
	   		
	   			g2.erase(g2.find(i));
	   		}
		}
	 }
void input()
{
	cout<<"Enter the total number nodes : ";
	cin>>tot;
	cout<<"Enter your current Floor : ";
	cin>>curr;
	cout<<"Enter the total number of inputs from within the lift : ";
	cin>>inc;
	cout<<"Enter the total number of inputs you want to enter from outside the lift : ";
	cin>>oc;
	if(inc>0)
	cout<<"Now Enter the floor numbers from within(E.g 3 , 5 , 7) ;\n";
	   first=idle;
	   state=idle;
	   
	   for(i=0;i<inc;i++)
	   {	
	   	cin>>temp;
	   	m.insert(temp);
	   }
	cout<<"Now Enter the floors for outside (E .g 3U , 5D , 1U ....etc)"<<endl;
	   for(i=0;i<oc;i++)
	   {
	   	cin>>g;
	   	if(g[1]=='U')
	   	{
	   		g1.insert(g[0]-'0');
	   	}

	   	else
	   	{
	   		g2.insert(g[0]-'0');
	   	}
	   }

}

void execute()
{
	cout<<curr<<"->";
	   int highest=tot;
	   int lowest=1;


	   if(curr-lowest>=highest-curr)
	   {
	   		first=up;
	   }
	   else
	   	first=down;


	 switch(first)
	 {
	 	case up:
	 	state=up;
	 	switch(state)
	 	{case up:
	 	moveup(curr,tot);
	 	state=down;

	 	case down:
	 	movedown(tot,lowest);
	 	state=up;
	 	moveup(lowest,curr);
	 	

	 	}
	 	break;

	 	case down:
	 	state=down;
	 	switch(state)
	 	{case down:
	 	movedown(curr,lowest);
	 	state=up;

	 	case up:
	 	moveup(lowest,highest);
	 	state=down;
	 	movedown(highest,curr);
	 	

	 	}
	 	break;

	 }
}
};


int main()
{
	liftop s1;
	s1.input();
	s1.execute();
	return 0;
}
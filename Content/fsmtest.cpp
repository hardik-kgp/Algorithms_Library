//*****************This code is submitted by Hardik Aggarwal*******************

#include<bits/stdc++.h>
using namespace std;
 

#define pb push_back
#define endl '\n'

enum dir{down,up,halt};

class liftop
{
private:
	int tot,curr,inc,oc,temp;
		set<int> m,g1,g2,ans;
	string g; 
	vector<int> v1;
	enum dir state;



public:
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
	   
	   for(int i=0;i<inc;i++)
	   {	

	   	cin>>temp;
	   	m.insert(temp);
	   	v1.pb(temp);
	   }
	cout<<"Now Enter the floors for outside (E .g 3U , 5D , 1U ....etc)"<<endl;
	   for(int i=0;i<oc;i++)
	   {
	   	cin>>g;
	   	v1.pb(g[0]-'0');
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

	void check()
	{
		
		int max=v1[0],min=v1[0];

		for(int i=0;i<v1.size();i++)
		{
			if(v1[i]<min)
				min=v1[i];
			if(v1[i]>max)
				max=v1[i];
		}

		if(curr-min>=max-curr)
			state=up;
		else
			state=down;
	}


	void ishaltup(int init)
	{
		if(m.find(init)!=m.end())
	   		{
	   			state=halt;
	   		
	   			m.erase(m.find(init));
	   		}

	   		else if(g1.find(init)!=g1.end())
	   		{
	   			state=halt;
	   			
	   			g1.erase(g1.find(init));
	   		}
		
	}

	void moveup(int init)
	 {	
	 	curr=init;
	 	//cout<<init<<'\n';
	 	ishaltup(init);

	 	if(state==halt)
		{
			cout<<init<<"->";
			state=up;
		}
	   
	   	if(init==tot+1)
			{	

				state=down;
				return ;
			}
		
		moveup(init+1);

	 }

	 void ishaltdown(int init)
	 {
	 	if(m.find(init)!=m.end())
	   		{
	   			state=halt;
	   			//ans.insert(init);
	   			m.erase(m.find(init));
	   		}

	   		else if(g2.find(init)!=g2.end())
	   		{
	   			state=halt;
	   		
	   			g2.erase(g2.find(init));
	   		}

	 }

void movedown(int init)
	 {	
	 		curr=init;
	 		//cout<<init<<'\n';
			ishaltdown(init);

	   		if(init==0)
	   			{	state=up;
	   				return ;
	   			}


	   		if(state==halt)
	   		{
	   			cout<<init<<"->";
	   			state=down;
	   		}
	   		movedown(init-1);
		
	 }


void execute()
{
	cout<<curr<<"->";
	check();
	 if(state==up)
	 	{
	 		moveup(curr);
	 		//cout<<"yep";
	 	//curr-=1;
	 		movedown(curr);
	 		//cout<<"yep";
	 		moveup(curr);

	 		

	 	}
	 	else
	 	{	
	 		//cout<<"moving down"<<endl;
	 		movedown(curr);
	 		moveup(curr);
	 		movedown(curr);
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



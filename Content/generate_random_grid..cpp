
#include<bits/stdc++.h> 
using namespace std; 
#define RUN 5 
#define MAX 5 
int N,M,eni,enj;
bool isvalid(int i,int j){
    return (i>=0&&j>=0&&i<N&&j<M);
}
#define MAXNUM 333
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};  
vector<pair<int,int>> path;
vector<vector<int>> vis;
int iter = 0;
bool dfs(int i,int j){

    iter++;
    if(iter>1e6)
        return false;
    vis[i][j] = true;
    path.push_back({i,j});
    vector<int> per(4);
    if(i == eni and j == enj)
        return true;
    iota(per.begin(),per.end(),0);
    random_shuffle(per.begin(),per.end());
    for(auto k:per){
        int ni = i+dx[k];
        int nj =  j+dy[k];
        if(!isvalid(ni,nj) || vis[ni][nj])
            continue;
        if(dfs(ni,nj)){
            return true;
        }
    }
    path.pop_back();
    return false;
}
int main() 
{  
    srand(time(NULL)); 
    //freopen("input_12.txt", "w", stdout);
    N = 1 + rand() % MAXNUM;  
    M  = 1 + rand() % MAXNUM;
    vector<vector<char>> grid(N,vector<char>(M,'P'));
    vis = vector<vector<int>>(N,vector<int>(M,0));
    int sti = (rand())%N;
    int stj = (rand())%M;  
    eni = rand()%N;
    enj = rand()%M;
    assert(!(sti == eni and enj == stj));
    cout<<N<<" "<<M<<endl;
    assert(dfs(sti,stj));
    for(auto j:path){
        grid[j.first][j.second] = 'O';
    }
    grid[sti][stj] = 'R';
    grid[eni][enj] = 'E';  
    int e = 0,r = 0;
    for(int i = 0;i<N;i++){
        for(int j =  0;j<M;j++){    
            if(grid[i][j] == 'P'){
                if(rand()%2)
                {
                    grid[i][j] = 'O';
                }
            }
            cout<<grid[i][j];
            if(grid[i][j] == 'E')
                e++;
            else if(grid[i][j] == 'R')
                r++;
        }
        cout<<endl;
    }
    assert(e == 1 and r == 1);
    // cout<<sti<<" "<<stj<<" "<<eni<<" "<<enj<<endl;
    return(0); 
} 
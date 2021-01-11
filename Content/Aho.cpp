#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define in insert
#define ld long double


#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =1e18;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll maxn = 100000+1;

template<int ALPHABET_SIZE,char MINIMAL_CHAR>
struct AhoCorasick {
    int ROOT_ID = 0;
    int currentNode;
    vector<array<int, ALPHABET_SIZE>> edges;
    vector<int> suffixLink;
    vector<long long> sum;
    AhoCorasick(vector<pair<string, int>> &a) : currentNode(ROOT_ID), edges(1),suffixLink(1, -1), sum(1, 0) {
        edges[ROOT_ID].fill(-1);
        for (auto &p : a) {
            int node = ROOT_ID;
            for (char c : p.first) {
                c -= MINIMAL_CHAR;
                if (edges[node][c] == -1) {
                    edges[node][c] = edges.size();
                    edges.emplace_back();
                    edges.back().fill(-1);
                    suffixLink.push_back(-1);
                    sum.push_back(0);
                }
                node = edges[node][c];
            }
            sum[node] += p.second;                       // use | operation here
        }
        queue<int> q;
        for (int ch = 0; ch < ALPHABET_SIZE; ++ch) {
          if (edges[ROOT_ID][ch] == -1) 
              edges[ROOT_ID][ch] = ROOT_ID;
          
        }
        for(int ch = 0;ch<ALPHABET_SIZE;ch++){
          if(edges[ROOT_ID][ch] != ROOT_ID){
            suffixLink[edges[ROOT_ID][ch]] = ROOT_ID; 
            q.push(edges[ROOT_ID][ch]); 

          }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int ch = 0; ch < ALPHABET_SIZE; ++ch) 
            { 
                if (edges[node][ch] != -1) { 
                    int suffix = suffixLink[node]; 
                    while(edges[suffix][ch] == -1) 
                        suffix = suffixLink[suffix];       
                    suffix = edges[suffix][ch]; 
                    suffixLink[edges[node][ch]] = suffix; 
                    sum[edges[node][ch]] += sum[suffix]; 
                    q.push(edges[node][ch]);
                } 
            }
      } 
    }

    void setNode(int node) {
        currentNode = node;
    }
    void resetNode() {
        setNode(ROOT_ID);
    }

    long long getCurrentNodeSum() {
        return sum[currentNode];
    }

    void move(char c) {
        c -= MINIMAL_CHAR; 
        while (edges[currentNode][c] == -1) 
            currentNode = suffixLink[currentNode]; 
        currentNode = edges[currentNode][c];
    }
    
};

int32_t main()
{ 
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  IOS 
  int t;
  cin>>t;
  while(t--){
    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    //trace(n);
    vector<pair<string, int>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
        
    }
    AhoCorasick<26, 'a'> ahoCorasick(s);
    ahoCorasick.resetNode();
    vector<long long> prefASum(a.size());
    vector<int> prefANode(a.size());
    for (int i = 0; i < a.size(); i++) {
        ahoCorasick.move(a[i]);
        prefASum[i] = ahoCorasick.getCurrentNodeSum();
        if (i != 0) {
            prefASum[i] += prefASum[i - 1];
        }
        prefANode[i] = ahoCorasick.currentNode;
    }
    //cout<<prefANode<<endl<<prefASum<<endl;
    ahoCorasick.resetNode();
    vector<long long> suffBSum(b.size());
    for (int i = 0; i < b.size(); i++) {
        ahoCorasick.move(b[i]);
        suffBSum[i] = ahoCorasick.getCurrentNodeSum();
    }
    for (int i = (int) b.size() - 2; i >= 0; i--) {
        suffBSum[i] += suffBSum[i + 1];
    }
    //cout<<suffBSum<<endl;

    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            long long cur = prefASum[i];

            ahoCorasick.setNode(prefANode[i]);
            for (int k = j; k <= j + 24 && k < b.size(); k++) {
                ahoCorasick.move(b[k]);
                cur += ahoCorasick.getCurrentNodeSum();
            }
            if (j + 25 < b.size()) {
                cur += suffBSum[j + 25];
            }
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
  }
 
   


}

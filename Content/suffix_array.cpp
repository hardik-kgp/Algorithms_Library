struct suffix_array{
  string s;
  vector<int>p, c, lcp;
  int n;
  suffix_array(string _s){
    s = _s;
    s += "$";
    n = s.size();
    p = vector<int>(n);
    c = p;
    lcp = vector<int>(n);
  }
  void count_sort(vector<pair<pair<int,int>,int>> &a){
    int n = a.size();
    vector<int> cnt(n);
    for(auto x:a){
      cnt[x.first.second]++;
    }
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1;i<n;i++){
      pos[i] = pos[i-1] + cnt[i-1];
    }
    vector<pair<pair<int,int>,int>> a_new(n);
    for(auto x:a){
      a_new[pos[x.first.second]] = x;
      pos[x.first.second]++;
    }
    a = a_new;
    cnt = vector<int>(n);
    for(auto x:a){
      cnt[x.first.first]++;
    }
    pos[0] = 0;
    for(int i = 1;i<n;i++){
      pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x:a){
      a_new[pos[x.first.first]] = x;
      pos[x.first.first]++;
    }
    a = a_new;
  }

  void build(){
      {
        // k = 0
        vector<pair<char,int>> a(n);
        for(int i = 0;i<n;i++){
          a[i] = {s[i],i};
        }
        sort(a.begin(), a.end());
        for(int i = 0;i<n;i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1;i<n;i++){
          if(a[i].first == a[i-1].first)
            c[p[i]] = c[p[i-1]];
          else c[p[i]] = c[p[i-1]] + 1;
        }
      } 
      int k = 0;
      while((1<<k) < n){
        vector<pair<pair<int,int>,int>>  a(n);
        for(int i = 0;i<n;i++){
          a[i] = {{c[i],c[(i + (1<<k))%n]},i};
        }
        count_sort(a);
        for(int i = 0;i<n;i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1;i<n;i++){
          if(a[i].first == a[i-1].first)
            c[p[i]] = c[p[i-1]];
          else c[p[i]] = c[p[i-1]] + 1;
        }
        k++;
      }
      
      k = 0;
      for(int i = 0;i<n-1;i++){
        int pi = c[i];
        int j = p[pi - 1];
        while(i+k<n and j+k<n and s[i+k] == s[j+k]) k++;
        lcp[pi-1] = k;
        k = max(0ll,k-1);
      }

  }
  void print(){
    for(int i = 0;i<n;i++){
      cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i])<<endl;
    }
  }

};
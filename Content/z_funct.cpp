vector<int> getZarr(string str) 
{ 
    int n = str.length(); 
    int L, R, k; 
    vector<int> Z(n); 
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    {  
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        {
            k = i-L; 
            if (Z[k] < R-i+1) 
                Z[i] = Z[k];  
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
    return Z;
} 

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
 
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])  j = pi[j-1];
        if (s[i] == s[j])  j++;
        pi[i] = j;
    }
 
    return pi;
}
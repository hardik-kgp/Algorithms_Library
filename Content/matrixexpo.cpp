ll sum(ll x, ll y)
{
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll N=3;
struct Matrix
{
	ll a[N][N];
 
	Matrix()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = 0;
	}
 
	Matrix operator * (const Matrix &X) const
	{
		Matrix res;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				res.a[i][j] = 0;
				for (int h = 0; h < N; h++)
				{
					res.a[i][j] = sum(res.a[i][j], mult(a[i][h], X.a[h][j]));
				}
			}
		return res;
	}
};
 
Matrix bin_pow(Matrix x, ll pow)
{
	if (pow == 1) return x;
	if (pow == 2) return x * x;
	if (pow & 1) return x * bin_pow(x, pow - 1);
	return bin_pow(bin_pow(x, pow / 2), 2);
}
 
Matrix generate()
{
	Matrix A;
	A.a={{10,-1,-4},{1,0,1},{0,0,1}};
	return A;
}

 
int main()
{
       #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    IOS
   ll k;
   cin>>k; 
   ll x=generate();
   x=bin_pow(x,k-1);
   ll ans=(x.a[0][0]*3+x.a[0][1]+x.a[0][2]+10*mod)%mod;
   cout<<ans;

 
    
}



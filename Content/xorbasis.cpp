struct vectorSpace{
	typedef ll base;
	int D, sz=0;
	vector<base> basis;	// basis[i] keeps the mask of the vector whose f value is i
	vectorSpace(int _D)
	{
		D=_D;
		basis.resize(D, 0);
	}
	void insert(base mask)
	{
		if(sz==D) return ;
		vector<pll> ops;
		for(int i=D-1; i>=0; --i){			
			if(!((mask>>i)&1)) continue;
			if(!basis[i]){
				basis[i]=mask;
				++sz;
				for (auto i : ops) {
					vec.pb({i.ff, i.ss, 1});
				}
				return ;
			}
			ops.pb({mask, basis[i]});
			have.insert(mask ^ basis[i]);
			mask^=basis[i];
		}
	}
	bool represent(base mask)
	{
		if(sz==D) return 1;
		for(int i=D-1; i>=0; --i){
			if(!((mask>>i)&1)) continue;
			if(!basis[i]) return 0;
			mask^=basis[i];
		}
		return 1;
	}
};
 
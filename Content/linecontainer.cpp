/**
 * Description: Given set of lines, computes the greatest y-coordinate(minmax=0) or smallest y-coordinate(minmax=1) for any x
 * Source: KACTL
 * Verification: CSA Squared Ends
 */
bool Q;
struct Line {
	mutable ll k, m, p;//slope, y-intercept, last optimal x
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<Line> {
	const bool minmax;
	LineContainer(bool minmax=0):minmax(minmax) {   // 0 for maximum for a given x and 1 for minimum for a given x
	}
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
	    if (b < 0) a *= -1, b *= -1;
	    if (a >= 0) return a/b;
	    return -((-a+b-1)/b);
	}

	// updates x->p, determines if y is unneeded
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return 0; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}

	void add(ll k, ll m) {
		if(minmax)
			k*=-1,m*=-1;
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}

	ll query(ll x) {
		assert(!empty());
		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
		return (minmax?-1:1)*(l.k * x + l.m);
	}
};

const int N = 200001;

struct ST {
    vector<int> t;
    int n;
    const int inf = 1e9;
    ST(int n): n(n) {
        t.resize(4*(n+2),0);
    }

    void build(int id, int l, int r, int a[]) {
        if(l == r) {
            t[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1,  lc = id << 1,  rc = lc | 1;
        build(lc, l, mid, a);
        build(rc, mid + 1, r, a);
        t[id] = min(t[lc] , t[rc]);
    }

    void upd(int id , int l, int r, int pos, int val) {
        if(l > pos || r < pos) return;
        if(l == r && l == pos) {
            t[id] = val;
            return;
        }
        int mid = (l + r) >> 1,  lc = id << 1,  rc = lc | 1;
        upd(lc, l, mid, pos, val);
        upd(rc, mid + 1, r , pos, val);
        t[id] = min(t[lc] ,  t[rc]);
    }
    int query(int id, int l, int r, int lq, int rq) {
        if(l > rq || r < lq) return inf;
        if(l >= lq && r <= rq) return t[id];
        int mid = (l + r) >> 1,  lc = id << 1,  rc = lc | 1;
        return min(query(lc, l, mid, lq, rq) , query(rc, mid + 1, r, lq, rq));
    }
} ;


struct Node{
	long long A[2][2];
};
 
void merge(Node& par, const Node& lef, const Node& rig){
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
			par.A[i][j] = INT_MIN;
		}
	}
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
			for(int k = 0; k < 2; ++k){
				par.A[i][k] = max(par.A[i][k], lef.A[i][j] + rig.A[j][k]);
			}
		}
	}
} 
void setv(Node& par, long long val){
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
			par.A[i][j] = (j - i) * val;
		}
	}
}
 
const int N = 3e5 + 10;
Node seg[4 * N];
int A[N];
#define M ((s + e) >> 1)
void build(int node, int s,int e){
	if (s == e){
		setv(seg[node], A[s]);
		return;
	}
	build(2 * node, s, M);
	build(2 * node + 1, M + 1, e);
	merge(seg[node], seg[2 * node], seg[2 * node + 1]);
}
 
void update(int node,int s,int e,int l,int v){
	if (e < l || s > l){
		return;
	}
	if (s == e){
		assert(s == l);
		setv(seg[node],v);
		return;
 
	}
 
	update(2 * node, s, M, l, v);
	update(2 * node + 1, M + 1, e, l, v);
	merge(seg[node], seg[2 * node], seg[2 * node + 1]);
}
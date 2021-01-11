#include<bits/stdc++.h>
using namespace std;
struct BCC{		// find AVs and bridges in an undirected graph
	vector<vector<int>> &edges;
	int V, counter = 0, root, rcs;		// root and # children of root
	vector<int> n,l;								// nodes,low
	stack<int> s;
	BCC(vector<vector<int>> &e) : edges(e), V(e.size()), n(V,-1), l(V,-1) {}
	bool visit(int u, int p) {			// also pass the parent
		l[u] = n[u] = counter++; s.push(u);
		for(auto &v : edges[u]){
			if (n[v] == -1) {
				if (u == root) rcs++; visit(v,u);
				if (l[v] >= n[u]) {}	// u is an articulation point
				if (l[v] > n[u]) {		// u<->v is a bridge
				} else {	// not bridge
				}
				l[u] = min(l[u], l[v]);
			} else if (v != p) {
				l[u] = min(l[u], n[v]);
				// u<->v biedge

			}
		}
		return false;
	}
	void run() {
		visit(0,-1);
	}
};

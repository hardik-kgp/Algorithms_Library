const int B = 60;
const int N = 100001;
struct Node {
	int ctr = 0, ch[2] = {0};
} block[N * B];
int root = 0;
int nxt = 1;
void trie_insert(int x) {
	int cur = root;
	for (int i = B - 1; i >= 0; --i) {
		bool bit = x & (1 << i);
		if (block[cur].ch[bit] == 0) {
			block[cur].ch[bit] = nxt++;
		}
		cur = block[cur].ch[bit];
		++block[cur].ctr;
	}
}
 
int check_and_remove(int x) {
	int cur = root, ans = 0;
	for (int i = B - 1; i >= 0; --i) {
		bool bit = x & (1 << i);
		int good = block[cur].ch[bit];
		if (good and block[good].ctr) {
			cur = good;
		} else {
			ans |= (1 << i);
			cur = block[cur].ch[!bit];
		}
		--block[cur].ctr;
	}
	return ans;
}
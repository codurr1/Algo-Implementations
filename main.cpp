
//Kth Ancestor
//Call preprocess function first
//Graph indexing from 1
int n, l;
vector<int> adj[MAXN];
vector<vector<int>> up;

void dfs(int v, int p) {
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (auto u : adj[v]) {
		if (u != p)
			dfs(u, v);
	}
}

int kth(int u, int k) {
	for (int i = l; i >= 0; i--) {
		if ((k >> i ) & 1)
			u = up[u][i];
	}
	return u ? u : -1;
}

void preprocess(int root) {
	l = ceil(log2(n));
	up.assign(n + 1, vector<int>(l + 1));
	dfs(root, 0);
}

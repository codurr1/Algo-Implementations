
//Topological Sort
vector<int> adj[MAXN];
vector<bool> vis;
vector<int> top_sort;

void dfs(int s) {
    vis[s]=1;
    for(auto u:adj[s]) {
        if(!vis[u])
            dfs(u);
    }
    top_sort.push_back(s);
}

void topsort(int n) {
    vis.assign(n,0);
    top_sort.clear();
    for(int i=0;i<n;i++) {
        if(!vis[i])
            dfs(i);
    }
    reverse(all(top_sort));
}

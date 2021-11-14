
//Lowest Common Ancestor
//Call preprocess function first
int n,l;
vector<int> adj[MAXN];
 
int timer;
vector<int> tin,tout;
vector<vector<int>> up;
 
void dfs(int v,int p) {
    tin[v]=++timer;
    up[v][0]=p;
    for(int i=1;i<=l;++i)
        up[v][i]=up[up[v][i-1]][i-1];
    for(auto u:adj[v]) {
        if(u!=p)
            dfs(u,v);
    }
    tout[v]=++timer;
}
 
bool is_ancestor(int u,int v) {
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
 
int lca(int u,int v) {
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=l;i>=0;--i) {
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    }
    return up[u][0];
}
 
void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer=0;
    l=ceil(log2(n));
    up.assign(n+1,vector<int>(l+1));
    dfs(root,root);
}


//DSU Implementation
struct DSU {
    vector<int> e;
    DSU(int N) {e=vector<int>(N,-1);}
    // get representative component (uses path compression)
    int get(int x) {return e[x]<0?x:e[x]=get(e[x]);}
    bool same_set(int a,int b) {return get(a)==get(b);}
    int size(int x) {return -e[get(x)];}
    bool unite(int x,int y) {  // union by size
        x=get(x),y=get(y);
        if(x==y) return false;
        if(e[x]>e[y]) swap(x,y);
        e[x]+=e[y];e[y]=x;
        return true;
    }
};


//Kruskal's Algorithm for MST
int kruskal (int n,vector<pair<int,pair<int,int>>> &ed) {
    sort(all(ed));
    int ans=0;
    DSU dsu(n+1);
    for(auto u:ed) if(dsu.unite(u.s.f,u.s.s)) ans+=u.f;
    return ans;
}

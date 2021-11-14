
//Dijkstra's Algorithm
vector<pair<int,int>> adj[MAXN];
vector<int> dis(MAXN,INF);

void dijkstra(int s=0) {
    using T=pair<ll,int>;
    priority_queue<T,vector<T>,greater<T>> pq;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()) {
        auto v=pq.top();
        pq.pop(); //v.f=min dist up to v.s
        if(v.f!=dis[v.s])continue;
        for(auto u:adj[v.s]) {
            if(v.f+u.s<dis[u.f])
                pq.push({dis[u.f]=v.f+u.s,u.f});
        }
    }
}


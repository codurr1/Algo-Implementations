
int edge_wt(int i,int j) {
	int wt=0;
	//edge weight function here
	wt=(A*min(i,j)+B*max(i,j))%MOD;
	return wt;
}

//PRIM'S ALGORITHM IMPLEMENTAION
//O(V^2) for Dense Graphs
//This Implementation works only for connected graphs
//nodes must be numbered from 1->n
int prims(int n) {
	vector<bool> sel(n+1,0);
	vector<pair<int,int>> ed(n+1,{INF,-1});
	int ans=0;
	sel[1]=1;
	for(int i=2;i<=n;i++)
		ed[i].f=edge_wt(i,1);
	int cnt=1;
	while(cnt!=n) {
		int x=INF;
		for(int i=1;i<=n;i++)
			if(!sel[i]) x=min(x,ed[i].f);
		for(int i=1;i<=n;i++) {
			if(!sel[i]&&ed[i].f==x) {
				ans+=x;
				cnt++;
				sel[i]=1;
				for(int j=1;j<=n;j++) {
					if(!sel[j]&&edge_wt(i,j)<ed[j].f) 
						ed[j]={edge_wt(i,j),i};
				}
			}
		}
	}
	return ans;
}


//Prime Factorisation

//Linear Sieve
//https://codeforces.com/blog/entry/54090
vector <int> prime;
int com[MAXN];
void sieve(int n=MAXN) {
    fill(com,com+n,0);
    for(int i=2;i<n;++i) {
        if(!com[i]) {
            prime.push_back(i);
            com[i]=i;
        }
        for(int j=0;j<sz(prime)&&i*prime[j]<n;++j) {
            com[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

//Prime Factorization O(lg(n))
//Call sieve() first
vector<int> pf(int x) {
    vector<int> ans;
    while(x!=1) {
        ans.push_back(com[x]);
        x=x/com[x];
    }
    return ans;
}

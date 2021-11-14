
//Linear Sieve
//https://codeforces.com/blog/entry/54090
vector <int> prime;
bool com[MAXN];
void sieve(int n=MAXN) {
    fill(com,com+n,false);
    for(int i=2;i<n;++i) {
        if(!com[i]) prime.push_back(i);
        for(int j=0;j<sz(prime)&&i*prime[j]<n;++j) {
            com[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}

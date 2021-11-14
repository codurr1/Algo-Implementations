#include<bits/stdc++.h>
using namespace std;

#define int long long //int main to signed main (Avoid if TC very close to limit)
#define sz(x) (int)((x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second

void setIO(string s="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

//Imp consts
const int MOD=1e9+7;
const int MAXN=2e5+1;
const int INF=1e18+5;

void solve() {
    
}

signed main()
{
    setIO();
    int t,i=1;
    cin>>t;
    while(t--) {
        cout<<"Case #"<<i++<<": ";
        solve();
    }
    return 0;
}

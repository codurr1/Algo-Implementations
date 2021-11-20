//Precompute facm()
//Binary Exponentiation
int pwr(int x,int y,int p=MOD) {
    int res=1;
    x%=p;
    if(!x) return 0;
    while(y>0) {
        if(y&1) res=(res*x)%p;
        y>>=1;
        x=(x*x)%p;
    }
    return res;
}

//Pre-computing fac and invfac 
//nCr%prime using FLT
//a^(p-2)=1/a (mod p) (Modular Inverse)

int inv(int a,int p=MOD) {
    return pwr(a,p-2,p);
}

vector<int> fac,invfac;
void facm(int p=MOD) {
    fac.resize(MAXN); //MAXN<=1e6
    invfac.resize(MAXN);
    fac[0]=invfac[0]=1;
    for(int i=1;i<MAXN;i++){
        fac[i]=(fac[i-1]*i)%p;
        invfac[i]=inv(fac[i],p);
    }
}

int ncr(int n,int r){
    if(n<r|||n<0||r<0) return 0;
    int ans=(fac[n]*invfac[r])%MOD;
    ans*=invfac[n-r];
    ans%=MOD;
    return ans;
}

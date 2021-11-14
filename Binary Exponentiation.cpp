
//Binary Exponentiation
int pwr(int x,int y,int p=MOD) {
    int res=1;
    x%=p;
    while(y>0) {
        if(y&1) res=(res*x)%p;
        y>>=1;
        x=(x*x)%p;
    }
    return res;
}

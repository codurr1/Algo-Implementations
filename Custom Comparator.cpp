
//Cust cmp for pairs
bool cmp(const pair<int,int> &x,const pair<int,int> &y){
    if(x.first==y.first)
        return x.second>y.second;//opposite to normal
    return x.first<y.first;
}

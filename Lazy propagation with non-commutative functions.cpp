
int n,ops[4*MAXN],vals[4*MAXN],a[MAXN];

int NO = 0; // for upd_op (out of range element)
int NE = INF; // for query_op (out of range element)

int upd_op(int a, int b, int len) {
    return (b==NO?a:b*len); //assignment
}

int query_op(int a, int b) {
    return a+b; //sum
}

void build(int node=1, int l=0, int r=n-1) {
    if(l==r) {
        vals[node]=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    vals[node]=query_op(vals[2*node],vals[2*node+1]);
}

void lazyprop(int node, int l, int r) {
    if(l==r) return;
    int mid=(l+r)/2;
    ops[2*node]=upd_op(ops[2*node],ops[node],1);
    vals[2*node]=upd_op(vals[2*node],ops[node],mid-l+1);
    ops[2*node+1]=upd_op(ops[2*node+1],ops[node],1);
    vals[2*node+1]=upd_op(vals[2*node+1],ops[node],r-mid);
    ops[node]=NO;
}

void upd(int ql, int qr, int val, int node=1, int l=0, int r=n-1) {
    lazyprop(node,l,r);
    if(qr<l||ql>r)
        return;
    if(l>=ql&&r<=qr) {
        ops[node]=upd_op(ops[node],val,1);
        vals[node]=upd_op(vals[node],val,r-l+1);
        return;
    }
    int mid=(l+r)/2;
    upd(ql,qr,val,2*node,l,mid);
    upd(ql,qr,val,2*node+1,mid+1,r);
    vals[node]=query_op(vals[2*node],vals[2*node+1]);
}

int query(int lq, int rq, int node=1, int l=0, int r=n-1) {
    lazyprop(node,l,r);
    if(rq<l||lq>r)
        return NE;
    if(lq<=l&&rq>=r)
        return vals[node];
    int mid=(l+r)/2;
    int s1 = query(lq,rq,2*node,l,mid);
    int s2 = query(lq,rq,2*node+1,mid+1,r);
    return query_op(s1,s2);
}

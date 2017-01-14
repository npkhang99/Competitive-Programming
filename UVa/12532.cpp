#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, k, a[N]={}, ST[4*N]={};

int getSign(int x){
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}

void build(int i, int l, int r){
    if(l == r){
        ST[i] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    ST[i] = ST[i*2] * ST[2*i+1];
}

long long update(int i, int l, int r, int pos, int new_val){
    if(pos < l || r < pos) return ST[i];
    if(l == pos && pos == r){
        a[pos] = new_val;
        return ST[i] = new_val;
    }
    int mid = (l+r)/2;
    long long p1, p2;
    p1 = update(i*2  ,     l, mid, pos, new_val),
    p2 = update(i*2+1, mid+1,   r, pos, new_val);
    return ST[i] = p1 * p2;
}

int rpq(int i, int l, int r, int L, int R){
    if(r < L || R < l || l > r) return 1;
    if(L <= l && r <= R) return ST[i];

    int mid = (l+r)/2,
        p1 = rpq(i*2, l, mid, L, R),
        p2 = rpq(i*2+1, mid+1, r, L, R);
    return p1 * p2;
}

int main(){
    while(~scanf("%d %d ",&n,&k)){
        for(int i=1; i<=n; i++){
            int x; scanf("%d ",&x);
            a[i] = getSign(x);
        }
        build(1,1,n);
        for(int i=1; i<=k; i++){
            char ch; int u, v;
            scanf("%c %d %d ",&ch,&u,&v);
            if(ch == 'P'){
                int q = rpq(1,1,n,u,v);
                if(q == 0) printf("0");
                else if(q < 0) printf("-");
                else printf("+");
            }else update(1,1,n,u,getSign(v));
        }
        printf("\n");
    }
    return 0;
}

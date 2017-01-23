// SPOJ submission 18568606 (C++ 5) plaintext list. Status: AC, problem QMAX2, contest SPOJVN. By mansblacks (Khang), 2017-01-13 16:48:14.
#include <bits/stdc++.h>
using namespace std;
 
const int N = 50009;
 
int n, m;
long long it[5*N]={}, lazy[5*N]={};
 
long long update(int i, int l, int r, int L, int R, long long v){
    if(lazy[i]){
        it[i] += lazy[i];
        if(l != r){
            lazy[2*i] += lazy[i];
            lazy[2*i + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
 
    if(r < L || R < l) return 0;
    if(L <= l && r <= R){
        if(l != r){
            lazy[2*i] += v;
            lazy[2*i + 1] += v;
        }
        return it[i] += v;
    }
 
    int mid = (l+r) / 2;
    return it[i] = max(it[i], max(update(2*i, l, mid, L, R, v), update(2*i + 1, mid+1, r, L, R, v)));
}
 
long long rmq(int i, int l, int r, int L, int R){
    if(lazy[i]){
        it[i] += lazy[i];
        if(l != r){
            lazy[2*i] += lazy[i];
            lazy[2*i + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
 
    if(r < L || R < l) return -1e18;
    if(L <= l && r <= R) return it[i];
 
    int mid = (l+r) / 2;
    return max(rmq(2*i, l, mid, L, R), rmq(2*i + 1, mid+1, r, L, R));
}
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int type, x, y, v;
        scanf("%d%d%d",&type,&x,&y);
        if(!type){
            scanf("%d",&v);
            update(1,1,n,x,y,v);
        }else printf("%lld\n", rmq(1,1,n,x,y));
    }
    return 0;
}
 

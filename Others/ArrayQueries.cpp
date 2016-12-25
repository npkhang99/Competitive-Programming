// LightOJ 1082
#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, q, a[N]={}, IT[4*N]={};

void buildIT(int i, int l, int r){
    if(l == r){
        IT[i] = a[l];
        return;
    }

    int mid = (l+r)/2;
    buildIT(2*i, l, mid);
    buildIT(2*i+1, mid+1, r);
    IT[i] = min(IT[2*i], IT[2*i+1]);
}

int rmq(int i, int l, int r, int L, int R){
    if(l > R || r < L) return 1e9;
    // fprintf(stderr, "%d %d\n", l,r);
    if(L <= l && r <= R) return IT[i];

    int mid = (l+r)/2;
    int p1 = rmq(2*i, l, mid, L, R),
        p2 = rmq(2*i+1, mid+1, r, L, R);
    return min(p1,p2);
}

int main(){
    int TC; scanf("%d",&TC);
    for(int T=1; T<=TC; T++){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        buildIT(1,1,n);
        
        printf("Case %d:\n",T);
        for(int i=0; i<q; i++){
            int x,y; scanf("%d%d",&x,&y);
            printf("%d\n",rmq(1,1,n,x,y));
        }
    }
    return 0;
}

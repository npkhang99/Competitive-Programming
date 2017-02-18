#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[2*N]={}, IT[8*N]={};

int build_IT(int i, int l, int r){
    if(l == r) return IT[i] = a[l];

    int mid = (l+r) >> 1;
    return IT[i] = min(build_IT(i*2, l, mid), build_IT(i*2+1, mid+1, r));
}

int rmq(int i, int l, int r, int L, int R){
    if(r < L || R < l) return 2e9;
    if(L <= l && r <= R) return IT[i];

    int mid = (l+r) >> 1;
    return min(rmq(i*2, l, mid, L, R), rmq(i*2+1, mid+1, r, L, R));
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        a[i+n] = a[i];
    }

    for(int i=1; i<=2*n; i++)
        a[i] += a[i-1];

    int ans = 0;
    build_IT(1,1,2*n);
    for(int i=1; i<=n; i++)
        if(rmq(1, 1, 2*n, i, i+n-1) - a[i-1] > 0) ans++;

    printf("%d\n", ans);
    return 0;
}

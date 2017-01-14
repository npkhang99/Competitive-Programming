#include <bits/stdc++.h>
using namespace std;

const int N = 50009;

int n, q, a[N]={}, IT1[4*N]={}, IT2[4*N]={};

void buildIT(int i, int l, int r){
    if(l == r){
        IT1[i] = IT2[i] = a[l];
        return;
    }

    int mid = (l+r) / 2;
    buildIT(i*2, l, mid);
    buildIT(i*2+1, mid+1, r);
    IT1[i] = max(IT1[i*2], IT1[i*2+1]);
    IT2[i] = min(IT2[i*2], IT2[i*2+1]);
}

int range_max(int i, int l, int r, int L, int R){
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return IT1[i];

    int mid = (l+r) / 2;

    int p1 = range_max(i*2, l, mid, L, R),
        p2 = range_max(i*2+1, mid+1, r, L, R);
    return max(p1,p2);
}

int range_min(int i, int l, int r, int L, int R){
    if(r < L || R < l) return 1e9;
    if(L <= l && r <= R) return IT2[i];

    int mid = (l+r) / 2;

    int p1 = range_min(i*2, l, mid, L, R),
        p2 = range_min(i*2+1, mid+1, r, L, R);
    return min(p1,p2);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Milk.inp","r",stdin);
    // freopen("Milk.out","w",stdout);
    cin>> n>> q;
    // scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)
        cin>> a[i];
        // scanf("%d",&a[i]);

    buildIT(1,1,n);

    for(int i=0; i<q; i++){
        int x, y; cin>> x>> y;
        cout<< range_max(1,1,n,x,y) - range_min(1,1,n,x,y)<< '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

inline void DEBUG(ii x){ fprintf(stderr, "%d %d\n", x.first, x.second); }

const int N = 1009;

int n, q, a[N][N]={};
ii it[4*N][4*N]={};

ii max_min(ii f, ii s){
    return ii(max(f.first, s.first), min(f.second, s.second));
}

void buildIT_y(int i, int li, int ri, int j, int lj, int rj){
    if(lj == rj){
        if(li == ri) it[i][j] = ii(a[li][lj], a[li][lj]);
        else it[i][j] = max_min(it[i*2][j], it[i*2+1][j]);
        return;
    }

    int mid = (lj + rj) >> 1;
    buildIT_y(i, li, ri, j*2, lj, mid),
    buildIT_y(i, li, ri, j*2+1, mid+1, rj);
    it[i][j] = max_min(it[i][j*2], it[i][j*2+1]);
}

void buildIT(int i, int l, int r){
    if(l != r){
        int mid = (l + r) >> 1;
        buildIT(i*2, l, mid);
        buildIT(i*2+1, mid+1, r);
    }
    buildIT_y(i, l, r, 1, 1, n);
}

void update_y(int i, int li, int ri, int j, int lj, int rj, int x, int y, int v){
    if(lj == rj){
        if(li == ri) it[i][j] = ii(v,v);
        else it[i][j] = max_min(it[i*2][j], it[i*2+1][j]);
        return;
    }

    int mid = (lj + rj) >> 1;
    if(y <= mid) update_y(i, li, ri, j*2, lj, mid, x, y, v);
    else update_y(i, li, ri, j*2+1, mid+1, rj, x, y, v);
    it[i][j] = max_min(it[i][j*2], it[i][j*2+1]);
}

void update(int i, int l, int r, int x, int y, int v){
    if(l != r){
        int mid = (l + r) >> 1;
        if(x <= mid) update(i*2, l, mid, x, y, v);
        else update(i*2+1, mid+1, r, x, y, v);
    }
    update_y(i, l, r, 1, 1, n, x, y, v);
}

ii rmq_y(int i, int j, int l, int r, int L, int R){
    if(r < L || R < l) return ii(-1e9,1e9);
    if(L <= l && r <= R) return it[i][j];

    int mid = (l + r) >> 1;
    ii  p1 = rmq_y(i, j*2, l, mid, L, R),
        p2 = rmq_y(i, j*2+1, mid+1, r, L, R);
    return max_min(p1,p2);
}

ii rmq(int i, int l, int r, int li, int ri, int lj, int rj){
    if(r < li || ri < l) return ii(-1e9,1e9);
    if(li <= l && r <= ri) return rmq_y(i, 1, 1, n, lj, rj);

    int mid = (l + r) >> 1;
    ii  p1 = rmq(i*2, l, mid, li, ri, lj, rj),
        p2 = rmq(i*2+1, mid+1, r, li, ri, lj, rj);
    return max_min(p1,p2);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    buildIT(1,1,n);

    scanf("%d", &q);
    while(q--){
        char type;
        scanf(" %c", &type);
        if(type == 'c'){
            int x, y, v; scanf("%d %d %d", &x, &y, &v);
            update(1, 1, n, x, y, v);
            continue;
        }

        int x, y, u, v; scanf("%d %d %d %d", &x, &y, &u, &v);
        ii ans = rmq(1, 1, n, x, u, y, v);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1100009;

int n, m, it[4*N]={}, lazy[4*N]={}, a[N]={};
char st[59]={};

void prep(){
    n = -1;
    scanf("%d ", &m);
    while(m--){
        int t; scanf("%d %s", &t, st);
        int l = strlen(st);
        while(t--){
            for(int i=0; i<l; i++)
                a[++n] = st[i] - '0';
        }
    }
}

int query_type(char t){
    if(t == 'F') return 1;
    if(t == 'E') return 2;
    if(t == 'I') return 3;
}

void propagate(int i, int l, int r){
    if(lazy[i] != 3){
        it[i] = (lazy[i] == 1) * (r - l + 1);
        if(l != r) lazy[i*2] = lazy[i*2+1] = lazy[i];
        lazy[i] = 0;
        return;
    }

    it[i] = (r - l + 1) - it[i];
    if(l != r){
        lazy[i*2] = 3 - lazy[i*2];
        lazy[i*2+1] = 3 - lazy[i*2+1];
    }
    lazy[i] = 0;
    return;
}

int buildIT(int i, int l, int r){
    lazy[i] = 0;
    if(l == r) return it[i] = a[l];
    int mid = (l+r) >> 1;
    return it[i] = buildIT(i*2, l, mid) + buildIT(i*2+1, mid+1, r);
}

int update(int i, int l, int r, int L, int R, int t){
    if(lazy[i]) propagate(i, l, r);

    if(r < L || R < l) return it[i];
    if(L <= l && r <= R){
        lazy[i] = t;
        propagate(i, l, r);
        return it[i];
    }

    int mid = (l + r) >> 1;
    return it[i] = update(i*2, l, mid, L, R, t) + update(i*2+1, mid+1, r, L, R, t);
}

int rsq(int i, int l, int r, int L, int R){
    if(lazy[i]) propagate(i, l, r);

    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return it[i];

    int mid = (l + r) >> 1;
    return rsq(i*2, l, mid, L, R) + rsq(i*2+1, mid+1, r, L, R);
}

int main(){
    int TC; scanf("%d", &TC);
    for(int TEST = 1; TEST <= TC; TEST++){
        printf("Case %d:\n", TEST);

        prep();
        buildIT(1, 0, n);

        scanf("%d", &m);
        int q = 0;
        while(m--){
            char type;
            int l, r;
            scanf(" %c %d %d", &type, &l, &r);
            if(type == 'S') printf("Q%d: %d\n", ++q, rsq(1, 0, n, l, r));
            else update(1, 0, n, l, r, query_type(type));
        }
    }
    return 0;
}

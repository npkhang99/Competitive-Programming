// Light OJ 1080 - Binary Simulation
#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, m, it[4*N]={};
bool lazy[4*N]={};
char a[N];

int builIT(int i, int l, int r){
    if(l == r) return it[i] = a[l] - 48;
    int mid = (l+r) >> 1;
    return it[i] = builIT(i*2, l, mid) + builIT(i*2+1, mid+1, r);
}

void invert(int i, int l, int r, int L, int R){
    if(lazy[i]){
        it[i] = (r - l +1) - it[i];
        lazy[i] = false;
        if(l != r){
            lazy[i*2] ^= true;
            lazy[i*2 + 1] ^= true;
        }
    }

    if(r < L || R < l) return;
    if(L <= l && r <= R){
        it[i] = (r - l +1) - it[i];
        if(l != r){
            lazy[2*i] ^= true;
            lazy[2*i + 1] ^= true;
        }
        return;
    }

    int mid = (l+r) >> 1;
    invert(i*2, l, mid, L, R);
    invert(i*2 + 1, mid+1, r, L, R);
}

int get_char(int i, int l, int r, int p){
    if(lazy[i]){
        it[i] = (r - l +1) - it[i];
        lazy[i] = false;
        if(l != r){
            lazy[i*2] ^= true;
            lazy[i*2 + 1] ^= true;
        }
    }

    if(r < p || p < l) return -1;
    if(l == p && r == p) return it[i];

    int mid = (l+r) >> 1;
    int p1 = get_char(i*2, l, mid, p),
        p2 = get_char(i*2 + 1, mid+1, r, p);

    return max(p1,p2);
}

int main(){
    int TC; scanf("%d ", &TC);
    for(int CASE = 1; CASE <= TC; CASE++){
        scanf("%s %d ", a+1, &m);
        n = strlen(a+1);
        builIT(1,1,n);
        memset(lazy, false, sizeof lazy);

        printf("Case %d:\n", CASE);
        for(int q=0; q<m; q++){
            int i, j; char type;
            scanf("%c %d ", &type, &i);
            if(type == 'I'){
                scanf("%d ", &j);
                invert(1,1,n,i,j);
            }else printf("%d\n", get_char(1,1,n,i));
        }
    }
    return 0;
}

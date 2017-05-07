#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> Query;

const int N = 30009;

int n, q, a[N]={}, b[N]={}, it[4*N]={}, ans[200009]={};
vector<Query> queries;

int comp(int i, int j){
    return a[i] < a[j];
}

int build(int i, int l, int r){
    if(l == r) return it[i] = 1;
    int mid = (l + r) >> 1;
    return it[i] = build(i*2, l, mid) + build(i*2+1, mid+1, r);
}

int update(int i, int l, int r, int p){
    if(r < p || p < l) return it[i];
    if(l == p && r == p) return it[i] = 0;

    int mid = (l + r) >> 1;
    return it[i] = update(i*2, l, mid, p) + update(i*2+1, mid+1, r, p);
}

int query(int i, int l, int r, int L, int R){
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return it[i];

    int mid = (l + r) >> 1;
    return query(i*2, l, mid, L, R) + query(i*2+1, mid+1, r, L, R);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        b[i] = i;
    }

    scanf("%d", &q);
    for(int i=0; i<q; i++){
        int x, y, z; scanf("%d %d %d", &x, &y, &z);
        queries.push_back(Query(ii(z,i),ii(x,y)));
    }

    sort(b+1, b+n+1, comp);
    sort(queries.begin(), queries.end());

    build(1,1,n);

    int i = 1;
    for(Query q : queries){
        while(i <= n && a[b[i]] <= q.first.first){
            update(1, 1, n, b[i]);
            i++;
        }
        ans[q.first.second] = query(1, 1, n, q.second.first, q.second.second);
    }

    for(int i=0; i<q; i++)
        printf("%d\n", ans[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, id;

    void read(int x){
        scanf("%d %d", &l, &r);
        id = x;
    }
};

const int N = 30009;

int n, m, a[N]={}, ans[1000009]={}, freq[1000009]={}, BASE;
vector<Query> q;

bool comp(const Query &a, const Query &b){
    return a.l / BASE < b.l / BASE || (a.l / BASE == b.l / BASE && a.r < b.r);
}

int add(int p){
    return ++freq[a[p]] == 1;
}

int remove(int p){
    return --freq[a[p]] == 0;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    BASE = sqrt(n);

    scanf("%d", &m);
    q.resize(m);
    for(int i = 0; i < m; i++)
        q[i].read(i);

    sort(q.begin(), q.end(), comp);
    int l = 2, r = 1, cnt = 0;
    for(Query query : q){
        while(l > query.l) cnt += add(--l);
        while(l < query.l) cnt -= remove(l++);
        while(r < query.r) cnt += add(++r);
        while(r > query.r) cnt -= remove(r--);
        ans[query.id] = cnt;
    }

    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}

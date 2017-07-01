#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, id;

    void read(int x){
        scanf("%d %d", &l, &r);
        id = x;
    }
};

const int N = 200009;

int n, m, a[N]={}, freq[1000009]={}, BASE;
long long ans[200009]={};
vector<Query> q;

bool comp(const Query &a, const Query &b){
    return a.l / BASE < b.l / BASE || (a.l / BASE == b.l / BASE && a.r > b.r);
}

long long add(int p){
    long long ret = -1ll * freq[a[p]] * freq[a[p]] * a[p];
    freq[a[p]]++;
    return ret + 1ll * freq[a[p]] * freq[a[p]] * a[p];
}

long long remove(int p){
    long long ret = -1ll * freq[a[p]] * freq[a[p]] * a[p];
    freq[a[p]]--;
    return ret + 1ll * freq[a[p]] * freq[a[p]] * a[p];
}

int main(){
    while(~scanf("%d %d", &n, &m)){
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        memset(freq, 0, sizeof freq);
        q.resize(m);
        BASE = sqrt(n);

        for(int i = 0; i < m; i++)
            q[i].read(i);

        sort(q.begin(), q.end(), comp);
        int l = 2, r = 1;
        long long c_ans = 0;
        for(Query query : q){
            while(l > query.l) c_ans += add(--l);
            while(l < query.l) c_ans += remove(l++);
            while(r < query.r) c_ans += add(++r);
            while(r > query.r) c_ans += remove(r--);
            ans[query.id] = c_ans;
        }

        for(int i = 0; i < m; i++)
            printf("%lld\n", ans[i]);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct query {
    int id;
    int l, r;
};

const int N = 200009;

int n, m, a[N] = {}, cnt[1000009] = {};
long long ans[N] = {};
vector<query> queries;

long long sqr(int x) {
    return 1LL * x * x;
}

void update(int i, int delta, int id) {
    ans[id] -= sqr(cnt[a[i]]) * a[i];
    cnt[a[i]] += delta;
    ans[id] += sqr(cnt[a[i]]) * a[i];
}

int main() {
    scanf("%d %d", &n, &m);
    
    assert(1 <= n && n <= 200'000);
    assert(1 <= m && m <= 200'000);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        
        assert(1 <= a[i] && a[i] <= 1'000'000);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        queries.push_back({i, l, r});
        
        assert(1 <= l && l <= n);
        assert(l <= r && r <= n);
    }

    int S = sqrt(n);

    sort(queries.begin(), queries.end(), [=](query a, query b) {
        if (a.l / S != b.l / S) {
            return a.l / S < b.l / S;
        }
        else {
            return a.r < b.r;
        }
    });

    int l = queries[0].l, r = queries[0].r;

    for (int i = l; i <= r; i++) {
        update(i, 1, queries[0].id);
    }

    for (int q = 1; q < m; q++) {
        ans[queries[q].id] = ans[queries[q - 1].id];

        while (l < queries[q].l) {
            update(l++, -1, queries[q].id);
        }

        while (l > queries[q].l) {
            update(--l, 1, queries[q].id);
        }

        while (r < queries[q].r) {
            update(++r, 1, queries[q].id);
        }

        while (r > queries[q].r) {
            update(r--, -1, queries[q].id);
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}

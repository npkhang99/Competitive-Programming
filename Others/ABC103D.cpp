#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, m;
ii a[N] = {};

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }

    sort(a, a + m);

    int ans = 0, r = 1e9;
    for (int i = 0; i < m; i++) {
        if (a[i].first >= r) {
            ans++;
            r = 1e9;
        }
        r = min(r, a[i].second);
    }

    printf("%d\n", ans + 1);
    return 0;
}

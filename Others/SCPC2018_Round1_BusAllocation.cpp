#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, k, a[N] = {};
set<int> s;

int main() {
    int TC; scanf("%d", &TC);
    for (int CASE = 1; CASE <= TC; CASE++) {
        scanf("%d %d", &n, &k);
        s.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }

        set<int>::iterator it = s.begin();
        while (it != s.end()) {
            set<int>::iterator it2 = s.upper_bound(*it + k);
            while (it2 != s.end()){
                set<int>::iterator temp = s.upper_bound(*it2 + k);
                s.erase(it2);
                it2 = temp;
            }
            it++;
        }

        printf("Case #%d\n%d\n", CASE, (int) s.size());
    }
    return 0;
}

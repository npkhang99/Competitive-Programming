#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, m;
set<int> a;
set<int>::iterator it;

int main(){
    while(scanf("%d %d", &n, &m), n && m){
        a.clear();
        for(int i=1; i<=n; i++){
            a.insert(i);
        }

        while(m--){
            int l, r; scanf("%d %d", &l, &r);
            a.erase(a.lower_bound(l), a.upper_bound(r));
            it = a.lower_bound(l);
            if(it == a.begin()) printf("* ");
            else printf("%d ", *(--it));
            it = a.lower_bound(r);
            if(it == a.end()) printf("*\n");
            else printf("%d\n", *it);
        }

        printf("-\n");
    }
    return 0;
}

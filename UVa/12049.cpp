#include <bits/stdc++.h>
using namespace std;

int n, m, T;
multiset<int> a, b;
multiset<int>::iterator a_it, b_it;

int main(){
    scanf("%d",&T);
    while(T--){
        a.clear(); b.clear();
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            a.insert(x);
        }
        for(int i=0; i<m; i++){
            int x; scanf("%d",&x);
            b.insert(x);
        }
        int ans = 0, a_loop = 0, b_loop = 0;
        a_it = a.begin(); b_it = b.begin();
        while(a_it != a.end() && b_it != b.end()){
            if(*a_it > *b_it){
                b_it++; b_loop++;
                ans += 1;
                continue;
            }
            if(*a_it < *b_it){
                a_it++; a_loop++;
                ans += 1;
                continue;
            }
            a_it++; a_loop++;
            b_it++; b_loop++;
        }
        ans += a.size() - a_loop + b.size() - b_loop;
        printf("%d\n",ans);
    }
    return 0;
}

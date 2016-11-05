#include <bits/stdc++.h>
using namespace std;

int n, m, t=0;
multiset<int> bill;
multiset<int>::iterator begin_it, end_it;

int main(){
    while(scanf("%d",&n), n){
        bill.clear();
        long long ans = 0;
        for(int _=0; _<n; _++){
            scanf("%d",&m);
            for(int i=0; i<m; i++){
                int x; scanf("%d",&x);
                bill.insert(x);
            }
            begin_it = bill.begin();
            end_it = bill.end(); end_it--;
            ans += *end_it - *begin_it;
            bill.erase(begin_it);
            bill.erase(end_it);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

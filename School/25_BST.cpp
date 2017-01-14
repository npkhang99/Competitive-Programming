#include <bits/stdc++.h>
using namespace std;

const int N=100009;

int n, m, a[N]={}, lowest=1, t, ans;
list<int> b;
list<int>::iterator it, pos[N];

int main(){
    scanf("%d%d",&n,&m);
    it = b.begin();
    for(int i=1; i<=n; i++){
        b.push_back(i), it = b.end();
        pos[i]=--it;
    }
    for(int i=0; i<m; i++){
        scanf("%d",&t);
        it = b.begin();
        printf("%lld %lld\n",&pos[t],&it);
        ans = ((&pos[t]) - (&it))/8;
        b.erase(pos[t]);
        b.push_front(t);
        pos[t] = b.begin();
        printf("%d ",ans);
    }
    printf("\n");
    return 0;
}

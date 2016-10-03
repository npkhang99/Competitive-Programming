#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N=100009;

int n, pos;
long a[N], d[N]={};
multiset<long> sum, del;
multiset<long>::iterator it, ans;

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%lld",&a[i]), d[i] = d[i-1]+a[i];
    del.insert(0); del.insert(n+1); sum.insert(d[n]);
    for(int i=1; i<=n; i++){
        scanf("%d",&pos);
        it = del.insert(pos);
        int last = *(--it), next = *(++(++it));
        sum.erase(sum.find(d[next-1]-d[last]));
        sum.insert(d[pos-1]-d[last]); sum.insert(d[next-1]-d[pos]);
        ans = sum.end();
        printf("%lld\n",*(--ans));
    }
    return 0;
}

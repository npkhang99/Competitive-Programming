#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[N]={}, x;
long long cnt[N]={}, ans = 0;

int main(){
    scanf("%d%d",&n,&x);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        int t = x ^ a[i];
        if(t > 1e5) continue;
        ans += cnt[t];
        cnt[a[i]] += 1;
    }
    printf("%lld\n",ans);
    return 0;
}

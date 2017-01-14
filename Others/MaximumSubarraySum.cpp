#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,int> ii;

const int N = 100009;

int n;
long long m, a[N]={}, b[N]={};
ii sum[N]={};

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d%lld",&n,&m);
        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
            b[i] = (b[i-1] + a[i]) % m;
            sum[i] = ii((sum[i-1].first + a[i]) % m, -i);
            printf("%lld%c",sum[i].first,i==n? '\n':' ');
        }

        sort(sum+1, sum+n+1); sum[n+1] = sum[n];
        long long ans = 0;
        for(int i=0; i<n; i++){
            ii need((m-1) - b[i], -n);
            // printf("%d %lld %lld\n",i,b[i],need.first);
            int p = lower_bound(sum+1, sum+n+1, need) - sum;
            if(p < 1 || -sum[p].second <= i) continue;
            // printf("%d - %lld %lld - %lld %d\n",i,b[i],need.first,sum[p].first,p);
            printf("%d -> %d - %lld + %lld\n",i,-sum[p].second,b[i],sum[p].first);
            ans = max(ans, (b[i] + sum[p].first) % m);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

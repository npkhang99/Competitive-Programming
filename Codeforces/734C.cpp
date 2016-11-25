#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200009;

int n, m, s, b[N]={}, d[N]={};
long long k, x, a[N]={}, c[N]={};

int main(){
    scanf("%lld %d %d %lld %d",&k,&n,&m,&x,&s);
    for(int i=0; i<n; i++)
        scanf("%lld",&a[i]);
    for(int i=0; i<n; i++)
        scanf("%d",&b[i]);
    for(int i=0; i<m; i++)
        scanf("%lld",&c[i]);
    for(int i=0; i<m; i++)
        scanf("%d",&d[i]);

    long long ans = k * x;
    for(int i=0; i<n; i++){
        if(s < b[i]) continue;
        int left = s - b[i];
        if(left >= d[0]){
            int j = upper_bound(d, d+m, left) - d - 1;
            ans = min(ans, a[i] * (k - c[j]));
        }else ans = min(ans, a[i] * k);
    }

    for(int i=0; i<m; i++)
        if(s < d[i]) continue;
        else ans = min(ans, x * (k - c[i]));

    printf("%lld\n",ans);
    return 0;
}

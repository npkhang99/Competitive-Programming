#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, a[N] = {};

int main(){
    freopen("Bang.inp","r",stdin);
    freopen("Bang.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i <n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    long long ans = 0, prev = 0;
    for(int i=0; i<n; i++)
        ans += prev + a[i], prev += a[i];
    printf("%lld\n",ans);
    return 0;
}

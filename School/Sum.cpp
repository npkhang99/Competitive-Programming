#include <stdio.h>
using namespace std;

const int N=10009;

int n, a[N]={}, k, b, c[2*N]={};

int main(){
    // freopen("Sum.inp","r",stdin);
    // freopen("Sum.out","w",stdout);
    scanf("%d%d%d",&n,&k,&b);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    b = (b-1)%n;
    long long ans = 0;
    if(k<=n){
        for(int i=b; i<b+k; i++) ans += a[i%n];
        printf("%lld\n",ans);
        return 0;
    }
    int cnt = k/n, left = k-cnt*n;
    for(int i=b; i<b+n; i++) ans += a[i%n];
    // printf("%lld %d\n",ans,left);
    ans*=cnt;
    for(int i=b; i<b+left; i++) ans += a[i%n];
    printf("%lld\n",ans);
    return 0;
}

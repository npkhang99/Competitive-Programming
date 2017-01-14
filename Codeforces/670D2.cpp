#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100009;

int n, k;
long long a[N]={}, b[N]={};

bool canBake(long long cookies){
    long long powderLeft = k;
    for(int i=0; i<n; i++){
        long long need = max(0ll, cookies * a[i] - b[i]);
        if(powderLeft < need) return false;
        powderLeft -= need;
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%lld",&a[i]);
    for(int i=0; i<n; i++)
        scanf("%lld",&b[i]);

    long long l = 1, r = 2*10E8, ans = 0;
    while(l <= r){
        long long mid = (l+r) / 2;
        if(canBake(mid)){
            ans = mid;
            l = mid+1;
        }else r = mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}

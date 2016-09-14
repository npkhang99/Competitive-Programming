#include <stdio.h>
#include <algorithm>
using namespace std;

long long d, k, a, b, t;

int main(){
    scanf("%lld%d%d%d%d",&d,&k,&a,&b,&t);
    if(d<=k){
        printf("%lld\n",a*d);
        return 0;
    }
    if(t+a*k > b*k){
        printf("%lld\n",a*k + b*(d-k));
        return 0;
    }
    long long cnt = d/k;
    printf("%lld\n",a*k*cnt + t*(cnt-1) + min(t+a*(d%k),b*(d%k)));
    return 0;
}

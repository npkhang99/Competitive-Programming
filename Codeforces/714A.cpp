#include <cstdio>
#include <algorithm>
using namespace std;

long long l1, r1, l2, r2, k, ans = 0;

int main(){
    scanf("%lld%lld%lld%lld%lld",&l1,&r1,&l2,&r2,&k);
    long long first = max(l1,l2), last = min(r1,r2);
    ans = max(0LL,last - first + 1);
    if(ans && first <= k && k <= last) ans-=1;
    printf("%lld\n",ans);
    return 0;
}

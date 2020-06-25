// AtCoder Grand Contest 012
#include <bits/stdc++.h>
using namespace std;

const int N = 300009;

int n, a[N];

int main(){
    scanf("%d", &n);
    for(int i=0; i<3*n; i++){
        scanf("%d", &a[i]);
        a[i] *= -1;
    }

    sort(a,a+3*n);
    long long ans = 0;
    for(int i=1; i<2*n; i+=2)
        ans += -1LL * a[i];

    printf("%lld\n", ans);
    return 0;
}

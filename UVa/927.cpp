#include <bits/stdc++.h>
using namespace std;

const int N = 29;

int d, k, n, c[N]={}, T;

long long f(int x){
    long long ans = 0;
    for(int i=0; i<=n; i++)
        ans += c[i] * pow(x,i);
    return ans;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0; i<=n; i++)
            scanf("%d",&c[i]);
        scanf("%d%d",&d,&k);
        int cur = d, i = 1;
        while(cur < k)
            cur += ++i * d;
        printf("%lld\n", f(i));
    }
    return 0;
}

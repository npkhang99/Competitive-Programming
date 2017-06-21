#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, h[N]={}, l[N]={}, r[N]={};
long long sum[N]={};

long long calc(long long x){
    return sum[n] - x * (x-1) - x;
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &h[i]);
            sum[i] = sum[i-1] + h[i];
        }

        l[1] = r[n] = 1;
        for(int i=2; i<=n; i++){
            l[i] = min(l[i-1]+1, h[i]);
        }

        for(int i=n-1; i>0; i--){
            r[i] = min(r[i+1]+1, h[i]);
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, min(r[i], l[i]));
        }

        printf("%lld\n", calc(ans));
    }
    return 0;
}

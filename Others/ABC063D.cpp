#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, a, b, h[N]={};

bool good(long long p){
    long long left = p;
    for(int i=1; i<=n; i++)
        if(h[i] - b * p > 0) left -= (int)round(ceil((h[i] - b * p) / (double)(a - b)));
    return left >= 0;
}

int main(){
    scanf("%d %d %d", &n, &a, &b);
    for(int i=1; i<=n; i++)
        scanf("%d", &h[i]);

    long long ans = 0, l = 1, r = 2e9;
    while(l <= r){
        long long mid = (l + r) >> 1;
        if(good(mid)){
            ans = mid;
            r = mid-1;
        }else l = mid+1;
    }

    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long n, s;

bool check(long long x){
    long long t = 0, a = x;
    while(x){
        t += (x % 10);
        x /= 10;
    }
    return a - t >= s;
}

int main(){
    while(~scanf("%lld %lld", &n, &s)){
        long long l = 0, r = n, ans = 0;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(check(mid)){
                r = mid - 1;
                ans = n - mid + 1;
            }else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

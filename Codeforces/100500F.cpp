#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main(){
    int TC; scanf("%d", &TC);
    for(int TEST=1; TEST<=TC; TEST++){
        scanf("%lld %lld", &n, &m);
        long long x = 0, y = 0, l = 1, r = n;
        while(l <= r){
            x = (l + r) >> 1;
            long long sum = x*(x+1) / 2;
            if(sum - x < m && sum >= m) break;
            if(sum - x >= m) r = x-1;
            else l = x+1;
        }
        y = m - x * (x-1) / 2;
        printf("Case %d: %lld %lld\n", TEST, --x, --y);
    }
    return 0;
}

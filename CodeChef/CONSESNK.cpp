#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, L, A, B, a[N]={};

long long get_dist(int p){
    long long t = 0;
    for(int i = 0; i < n; i++)
        t += 1ll * abs(a[i] - (p + i*L));
    return t;
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d %d", &n, &L, &A, &B);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a,a+n);
        int l = A, r = B - n * L;
        long long ans = 1e18;
        while(l <= r){
            int m1 = l + (r - l) / 3,
                m2 = r - (r - l) / 3;
            
            if(get_dist(m1) < get_dist(m2)){
                r = m2 - 1;
                ans = get_dist(m1);
            }else{
                l = m1 + 1;
                ans = get_dist(m2);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

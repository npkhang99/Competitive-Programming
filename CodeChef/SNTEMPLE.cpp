#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[N]={}, it[4*N]={};
long long sum[N]={};

long long sum_range(int f, int l){
    return sum[l] - sum[f-1];
}

long long sum_cont(long long f, long long l){
    return f == 1? (l * (l+1) / 2) : (sum_cont(1,l) - sum_cont(1,f-1));
}

int build(int i, int l, int r){
    if(l == r) return it[i] = l;
    int mid = (l + r) >> 1,
        p1 = build(i*2, l, mid),
        p2 = build(i*2+1, mid+1, r);
    return it[i] = a[p1]<a[p2]? p1:p2;
}

int rmq(int i, int l, int r, int L, int R){
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return it[i];

    int mid = (l + r) >> 1,
        p1 = rmq(i*2, l, mid, L, R),
        p2 = rmq(i*2+1, mid+1, r, L, R);
    return a[p1] < a[p2]? p1:p2;
}

long long calc(int i, int j){
    if(a[i] - a[j] <= abs(i-j)){
        int heigh = min(a[i], min(i, n-i+1));
        return sum_range(1,n) - 2*sum_cont(1,heigh-1) - heigh;
    }

    int heigh = min(min(a[i], min(i, n-i+1)), a[j] + abs(i-j));
    return sum_range(1,n) - 2*sum_cont(1,heigh-1) - heigh;
}

int main(){
    int TC; scanf("%d", &TC);
    a[0] = 2e9;
    while(TC--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }

        build(1, 1, n);

        long long ans = 1e18;
        for(int i=1; i<=n; i++){
            int range = min(a[i], min(i-1, n-i));
            if(!range){
                ans = min(ans, sum_range(1,n) - 1);
                continue;
            }

            int p1 = rmq(1, 1, n, i-range, i-1),
                p2 = rmq(1, 1, n, i+1, i+range);

            ans = min(ans, max(calc(i, p1), calc(i, p2)));
        }

        printf("%lld\n", ans);
    }
    return 0;
}

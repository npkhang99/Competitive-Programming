// CodeChef - SnackDown Online Qualifier 2017
#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, q, a[N];
long long sum[N]={};

long long rsq(int l, int r){
    return sum[r] - sum[l-1];
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++)
            scanf("%d", &a[i]);

        sort(a+1, a+n+1);
        for(int i=1; i<=n; i++)
            sum[i] = sum[i-1] + a[i];

        while(q--){
            int lim; scanf("%d", &lim);
            int p = upper_bound(a+1, a+n+1, lim) - a - 1;

            int l = n - p + 1, r = n, ans = l - 1, already_met = l - 1;
            while(l <= r){
                int mid = (l + r) >> 1;
                int need_more = mid - already_met;

                if(1LL * lim * need_more - rsq(p - need_more + 1, p) <= n - already_met - need_more){
                    l = mid + 1;
                    ans = mid;
                }else r = mid - 1;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

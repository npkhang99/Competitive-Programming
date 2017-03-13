#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 60009;

int n;
ii a[N];

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i].first);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i].second);

    sort(a,a+n);

    double l = a[0].first, r = a[n-1].first, ans = 1e9;
    for(int loop=0; loop < 1e4; loop++){
        double mid = (l+r) / 2.0, wait = 0.0;
        int p = 0;
        for(int i=0; i<n; i++){
            double need = fabs(a[i].first - mid) / (double)a[i].second;
            if(need - wait > 1e-9){
                wait = need;
                p = i;
            }
        }

        ans = min(ans, wait);
        if(a[p].first - mid > 1e-9) l = mid;
        else r = mid;
    }

    printf("%.12lf\n", ans);
    return 0;
}

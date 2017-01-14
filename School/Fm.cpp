#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long llong;

const int N=100009;

int n, m, a[N], cnt[1000009]={}, k=0;
vector<int> fixed;

int main(){
    // freopen("Fm.inp","r",stdin);
    // freopen("Fm.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    for(int i=0; i<n; i++)
        if(a[i]<=m && !cnt[a[i]]++) fixed.push_back(a[i]), k+=1;
    sort(fixed.begin(),fixed.end());

    llong ans = 0;
    // special
    if(k==1){
        if(m%2==0 && fixed[0]==m/2) ans = llong(cnt[fixed[0]])*llong(cnt[fixed[0]]);
        else ans = 0;
        printf("%lld\n",ans);
        return 0;
    }

    llong lowest = fixed[0], highest = fixed[k-1], start = 1, end = m;
    // optimize start
    start = max(start,lowest*2);
    // optimize end
    end = min(highest*2,end);
    // iterate from start -> end
    for(llong i=start; i<=end; i++){
        llong p = 0, lo = lowest, hi = i-lowest;
        while(lo<=hi){
            if(lo==hi) p += llong(cnt[lo++])*llong(cnt[hi--]);
            else p+=llong(cnt[lo++])*llong(cnt[hi--])*2;
        }
        // printf("%lld %lld\n",i,p);
        ans += p;
    }
    printf("%lld\n",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N=100009;

int n, a[N]={}, L1[N]={}, L2[N]={};
set<ii> sum_j;

int main(){
    freopen("DSEG.inp","r",stdin);
    freopen("DSEG.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]), L1[i] = L1[i-1] + a[i];
    for(int i=n; i>0; i--)
        L2[i] = L2[i+1] + a[i], sum_j.insert(ii(L2[i],i));

    // for(int i=1; i<=n; i++) printf("%5d ",L1[i]); printf("\n");
    // for(int i=1; i<=n; i++) printf("%5d ",L2[i]); printf("\n");

    int ans = -10E8;
    set<ii>::iterator it;
    for(int i=1; i<n; i++){
        sum_j.erase(ii(L2[i],i));
        it = sum_j.end();
        ans = max(ans, max(abs(L1[i] - (*(--it)).first), abs(L1[i] - (*(sum_j.begin())).first)));
    }
    printf("%d\n",ans);
    return 0;
}

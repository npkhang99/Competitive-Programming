#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N=300009;

int n, m;
vector<ii> a;

int main(){
    // freopen("RIJ.inp","r",stdin);
    // freopen("RIJ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++){
        int x, y; scanf("%d%d",&x,&y);
        if(x<=y) continue;
        a.push_back(ii(y,x));
    }

    sort(a.begin(),a.end());
    // for(int i=0; i<a.size(); i++) printf("%d %d\n",a[i].first,a[i].second);
    int l = a[0].first, r = a[0].second;
    long long ans = m;
    for(int i=1; i<a.size(); i++){
        if(a[i].first <= r) r = a[i].second;
        else ans += 2*(r - l), l = a[i].first, r = a[i].second;
    }
    ans += 2*(r - l);
    printf("%lld\n",ans);
    return 0;
}

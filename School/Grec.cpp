#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<long long,int> ii;

const int N=20009;

int n, x, k=1;
vector<ii> a;

int main(){
    // freopen("Grec.inp","r",stdin);
    // freopen("Grec.out","w",stdout);
    while(~scanf("%d",&x)) a.push_back(ii(x,k++));
    sort(a.begin(),a.end(),greater<ii>());
    long long ans = 0;
    for(int i=0; i<a.size(); i+=2) ans += a[i].first*a[i+1].first;
    printf("%lld\n",ans);
    for(int i=0; i<a.size(); i+=2) printf("%d %d\n",a[i].second,a[i+1].second);
    return 0;
}

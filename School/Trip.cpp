#include <cstdio>
#include <algorithm>
using namespace std;

const int N=10009;

int n, m, a[N]={};

int main(){
    // freopen("Trip.inp","r",stdin);
    // freopen("Trip.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    sort(a,a+n);
    int i = 0, j = n-1, ans = 0;
    while(j > i){
        while(j > i && a[i]+a[j] > m) j-=1;
        if(j>i) ans += 1, i+=1, j-=1, n-=2;
    }
    ans += n;
    printf("%d\n",ans);
    return 0;
}

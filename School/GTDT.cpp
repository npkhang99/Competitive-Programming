#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 19;

int n, a[N]={};

int main(){
    // freopen("GTDT.inp","r",stdin);
    // freopen("GTDT.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] > 10) ans += max(a[i], (int)round(pow(a[i]/10,a[i]%10)));
        else ans += a[i];
    }
    printf("%d\n",ans);
    return 0;
}

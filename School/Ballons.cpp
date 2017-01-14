#include <cstdio>
using namespace std;

const int N=1000009;

int n, a[N]={}, b[N]={};

int main(){
    freopen("Ballons.inp","r",stdin);
    freopen("Ballons.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    int ans = 0;
    for(int i=0; i<n; i++){
        if(!b[a[i]]) b[a[i]-1] += 1, ans += 1;
        else b[a[i]] -= 1, b[a[i]-1] += 1;
    }
    printf("%d\n",ans);
    return 0;
}

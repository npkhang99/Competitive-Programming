#include <cstdio>
#include <algorithm>
using namespace std;

const int N=2009;

int n, a[N]={}, LIS[N]={}, LDS[N]={}, T;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&a[n-i-1]), LIS[i] = LDS[i] = 1;

        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++){
                if(a[i] > a[j]) LIS[i] = max(LIS[i],LIS[j]+1);
                if(a[i] < a[j]) LDS[i] = max(LDS[i],LDS[j]+1);
            }
        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans,LIS[i] + LDS[i] - 1);
        printf("%d\n",ans);
    }
    return 0;
}

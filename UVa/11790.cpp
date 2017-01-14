#include <cstdio>
#include <algorithm>
using namespace std;

const int N=10009;

int n, a[N]={}, b[N]={}, LIS[N]={}, LDS[N]={}, T;

int main(){
    scanf("%d",&T);
    for(int t=0; t<T;){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        for(int i=0; i<n; i++) scanf("%d",&b[i]), LIS[i] = LDS[i] = b[i];

        int lis=0, lds=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[i] > a[j]) LIS[i] = max(LIS[i], LIS[j]+b[i]);
                if(a[i] < a[j]) LDS[i] = max(LDS[i], LDS[j]+b[i]);
            }
            lis = max(lis,LIS[i]);
            lds = max(lds,LDS[i]);
        }
        
        if(lis >= lds) printf("Case %d. Increasing (%d). Decreasing (%d).\n",++t,lis,lds);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n",++t,lds,lis);
    }
    return 0;
}

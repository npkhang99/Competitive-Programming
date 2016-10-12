#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=5100;

int n, a[N]={};
long long sum[N]={};

int main(){
    freopen("TwoSum.inp","r",stdin);
    freopen("TwoSum.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    int ans = 0;
    for(int l=1; l<n; l++)
        for(int r=l+1; r<=n; r++){
            // printf("%d %d %d %d\n",l,r,sum[r]-sum[l-1],binary_search(sum+l,sum+r+1,(sum[r]-sum[l-1])/2+sum[l-1]));
            if((sum[r]-sum[l-1])%2==0 && binary_search(sum+l,sum+r+1,(sum[r]-sum[l-1])/2+sum[l-1])) ans = max(ans,r-l+1);
        }
    printf("%d\n",ans);
    return 0;
}

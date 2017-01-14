#include <cstdio>
#include <algorithm>
using namespace std;

const int LIM_M = 20000;

int n, m, a[109]={}, TC, dp[20009];

int main(){
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&m,&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<=LIM_M; i++)
            dp[i] = 10E8;
        dp[0] = 0;
        for(int i=0; i<n; i++)
            for(int j=LIM_M - a[i]; j >= 0; j--) // trick: loop backward for not using a bill twice!
                dp[j+a[i]] = min(dp[j + a[i]], dp[j] + 1);

        for(int i=m; i<=LIM_M; i++)
            if(dp[i] != 10E8){
                printf("%d %d\n",i,dp[i]);
                break;
            }
    }
    return 0;
}

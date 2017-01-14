#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int d[] = {5,10,20,50,100,200};

int m, a[9], dp[5009] = {}, change[5009] = {};

void prep(){
    for(int i=1; i<509; i++)
        change[i] = 1e9;

    for(int i=0; i<6; i++)
        for(int j=0; j<5000; j++)
            if(change[j] != 1e9){
                int k = 1;
                if(j + d[i]*k <= 5000)
                    change[j + d[i]*k] = min(change[j + d[i]*k], change[j] + k);
                k++;
            }
}

int main(){
    prep();
    while(scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]), a[0] || a[1] || a[2] || a[3] || a[4] || a[5]){
        double x; scanf("%lf",&x);
        m = x*100;
        for(int i=0; i<=5000; i++)
            dp[i] = 1e9;

        dp[0] = 0;
        for(int i=0; i<6; i++)
            for(int j=0; j<=m+200; j++)
                if(dp[j] != 1e9)
                    for(int k=1; k<=a[i]; k++)
                        dp[j + d[i]*k] = min(dp[j + d[i]*k], dp[j] + k);
        int ans = 1e9;
        for(int i=m; i<=5000; i++)
            if(dp[i] != 1e9)
                ans = min(ans, dp[i]+change[i-m]);
        printf("%3d\n",ans);
    }
    return 0;
}

#include <cstdio>
using namespace std;

const int N = 109;

int n, k, dp[N][N]={};

int main(){
    for(int i=0; i<=100; i++)
        dp[i][1] = 1;
    for(int j=2; j <= 100; j++)
        for(int i=0; i <= 100; i++)
            for(int k=0; k <= 100-i; k++){
                dp[i + k][j] += dp[i][j-1];
                dp[i + k][j] %= (int)10E5;
            }

    while(scanf("%d%d",&n,&k), n || k)
        printf("%d\n",dp[n][k]);
    return 0;
}

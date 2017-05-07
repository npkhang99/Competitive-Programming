#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n;
long long a[N]={}, memo[N][N]={}, b[N][N]={};

long long dp(int i, int j){
    if(i == j) return 0;
    if(memo[i][j]!=-1) return memo[i][j];

    long long temp = 1e18;
    for(int k=i; k<j; k++)
        temp = min(temp, b[i][k] * b[k+1][j] + dp(i,k) + dp(k+1,j));
    return memo[i][j] = temp;
}

int main(){
    while(~scanf("%d",&n)){
        for(int i=1; i<=n; i++)
            scanf("%lld",&a[i]);

        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j++)
                b[i][j] = (b[i][j-1] + a[j]) % 100;

        memset(memo, -1, sizeof memo);

        printf("%lld\n", dp(1,n));
    }
    return 0;
}

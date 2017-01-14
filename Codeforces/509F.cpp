#include <iostream>
using namespace std;

const int N = 509;
const int MOD = 10E8+7;

int n, a[N];
long long dp[N][N]={};

int main(){
    cin>> n;
    for(int i=1; i<=n; i++) cin>> a[i];

    for(int i=1; i<=n; i++) dp[i][i] = 1;
    for(int i=n-1; i>0; i--){
        for(int j=i+1; j<=n; j++){
            for(int k=i+1; k<=j; k++)
                if(a[i+1] < a[k+1] || k == j){
                    dp[i][j] += dp[i+1][k] * dp[k][j];
                    dp[i][j] %= MOD;
                }
        }
    }

    cout<< dp[1][n]<< endl;
    return 0;
}

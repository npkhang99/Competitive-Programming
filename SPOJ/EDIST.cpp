#include <bits/stdc++.h>
using namespace std;

const int N = 2009;

int n, m, dp[N][N]={};
string a, b;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int TC; cin>> TC;
    while(TC--){
        cin>> a>> b;
        n = a.size(); m = b.size();

        for(int i=0; i<=n; i++)
            dp[i][0] = i;
        for(int i=0; i<=m; i++)
            dp[0][i] = i;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;

        cout<< dp[n][m]<< endl;
    }
    return 0;
}

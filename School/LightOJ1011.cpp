#include <iostream>
#include <stdio.h>
using namespace std;

int max(int a, int b){ return (a>b)?a:b; }

const int N=17;

int n, a[N][N], T, dp[N][1<<N];

int main(){
    cin>> T;
    for(int t=0; t<T; t++){
        // read input
        cin>> n;
        for(int i=1; i<=n; i++)
            for(int j=0; j<n; j++) cin>> a[i][j];
        // innit
        for(int i=0; i<=n; i++)
            for(int j=0; j<(1<<n); j++) dp[i][j]=0;
        // do THE job
        // dp[i][mask] -> gia tri max khi co i nguoi nam ket hon voi tap cac nguoi nu la mask
        
        // xet nguoi nam thu i voi i nguoi nam
        for(int i=1; i<=n; i++){
            // xet tap cac nguoi nu
            for(int mask=1; mask<(1<<n); mask++){
                // so luong cac nguoi nu
                int cnt = __builtin_popcount(mask);
                // kiem tra neu so nguoi nu == so nguoi nam
                if(cnt==i){
                    // xet nguoi nu thu x ket hon voi nguoi nam thu i
                    for(int x=0; x<n; x++)
                        if((1<<x)&mask){
                            // lay tap nu truoc khi lay nguoi nu thu x
                            int preMask = mask - (1<<x);
                            // lay max cua hien tai va gia tri luc truoc + gia tri ket nap i voi x
                            dp[i][mask] = max(dp[i][mask],dp[i-1][preMask] + a[i][x]);
                        }
                }
            }
        }
        // print ans
        printf("Case %d: %d\n",t+1,dp[n][(1<<n)-1]);
    }
    return 0;
}

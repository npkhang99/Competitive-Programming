#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int abs(int a){ return (a<0)?-a:a; }

const int N=109;
const int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

int n, a[N]={}, dp[N][1<<18]={}, fact[N]={}, ans[N]={};

void xuly(){
    // fact[i] la tap cac uoc nguyen to cua i
    for(int i=1; i<61; i++)
        for(int j=0; j<17; j++)
            if(i%prime[j]==0) fact[i] = fact[i] | (1<<j);

    // Goi dp[i][mask] tong gia tri |a[k]-b[k]| (k : 1 -> i)
    // nho nhat ma i phan tu ban dau cua day b chia het cho cac uoc trong tap mask

    // xet phan tu thu i trong a
    for(int i=1; i<=n; i++)
        // xet tap cac so nguyen to
        for(int mask=0; mask<(1<<17); mask++){
            dp[i][mask] = 10E8;
            // chon x bat ky
            for(int x=0; x<61; x++)
                // xet tap cac uoc nguyen to cua x (fact[x])
                // co la tap con cua tap cac so nguyen to dang xet hay khong (mask)
                if((fact[x] | mask) == mask)
                    dp[i][mask] = min(dp[i][mask], dp[i-1][mask-fact[x]]+abs(a[i]-x));
        }
    // lay ket qua
    int sum=10E8, m=0;
    for(int mask=0; mask<(1<<17); mask++)
        sum = (sum>dp[n][mask])?(m = mask, dp[n][mask]):sum;
    // back trace
    for(int i=n; i>0; i--)
        for(int x=0; x<61; x++)
            if((fact[x] | m) == m && dp[i-1][m-fact[x]]+abs(a[i]-x) == dp[i][m]){
                m-=fact[x];
                ans[i]=x;
                break;
            }
    // in kq
    for(int i=1; i<=n; i++) printf("%d ",ans[i]);
}

int main(){
    cin>> n;
    for(int i=1; i<=n; i++) cin>> a[i];
    xuly();
    return 0;
}

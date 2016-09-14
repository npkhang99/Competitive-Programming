// SPOJ submission 17233317 (C++ 5) plaintext list. Status: AC, problem LEM3, contest SPOJVN. By mansblacks (Khang), 2016-07-06 08:26:50.
#include <iostream>
#include <algorithm>
using namespace std;

const int N=19;

int a[N][N], n, dp[N][1<<N];

void doc(){
    cin>> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin>> a[i][j];
}

void xuly(){
    int _n=1<<n;
    for(int i=0; i<n; i++)
        for(int j=0; j<_n; j++) dp[i][j]=10E8;
    
    /*
     * dp[i][mask] la gia tien nho nhat neu di tap hop cac thanh pho mask
     * voi i la thanh pho di cuoi cung
     */
     
    // khoi tao cac thanh pho xuat phat voi gia tien = 0
    for(int i=0; i<n; i++) dp[i][1<<i] = 0;
    
    // quet mask
    for(int mask=1; mask<_n; mask++){
        // dem so luong cac thanh pho phai tham quan trong mask
        int cnt = __builtin_popcount(mask);
        // neu chi co 1 thanh pho thi bo qua (vi da gan = 0 nhu tren)
        if(cnt==1) continue;
        // khong thi chon 1 thanh pho bat ki trong tap mask lam thanh pho cuoi cung
        for(int i=0; i<n; i++)
            // xet xem thanh pho i co trong mask hay khong
            // (neu khong thi phep & (and) se tra ve 0 (false) va khong lam cac lenh trong if{})
            if(mask & (1<<i)){
                // lay mask luc truoc neu bo di thanh pho i
                int preMask = mask - (1<<i);
                // quet tiep thanh pho cuoi cung di trong mask truoc
                for(int j=0; j<n; j++)
                    // xet xem thanh pho j co trong preMask hay khong
                    if(preMask & (1<<j))
                        // toi uu dp[i][mask]
                        dp[i][mask] = min(dp[i][mask], dp[j][preMask] + a[j][i]);
            }
    }
    int ans=10E8;
    // quet mot lan qua n thanh pho la thanh pho di cuoi cung de lay ket qua
    for(int i=0; i<n; i++) ans = min(ans, dp[i][_n-1]);
    cout<< ans;
}

int main(){
    doc();
    xuly();
    return 0;
}

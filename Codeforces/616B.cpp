#include <iostream>
#include <algorithm>
using namespace std;

const int N=109;
int a[N][N]={}, n, m, d[N]={};

void doc(){
    cin>> n>> m;
    for(int i=1; i<=n; i++){
        d[i]=10E8;
        for(int j=1; j<=m; j++){
            cin>> a[i][j];
            d[i]=min(d[i], a[i][j]);
        }
    }
}

void xuly(){
    int ans=-10E8;
    for(int i=1; i<=n; i++) ans=max(ans, d[i]);
    cout<< ans;
}

int main(){
    doc();
    xuly();
    return 0;
}
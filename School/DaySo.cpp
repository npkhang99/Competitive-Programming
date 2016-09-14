#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;

bitset<8> a[125000];
//---------------------------------------------------------
int main(){
    int n,m,x;
    freopen("DaySo.inp","r",stdin);
    cin>> n>> m;
    for(int i=1; i<=n; i++){
        cin>> x;
        a[x >> 8].set(x & 7);
    }
    for(int i=1; i<=m; i++){
        cin>> x;
        if(a[x >> 8].test(x & 7)) cout<< x<< " ";
    }
    int count=0;
    return 0;
}
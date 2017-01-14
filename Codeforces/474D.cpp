#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;
const int MOD=10E8+7;

int n, k;
long long a[N]={}, L[N]={};

void xuly(){
    for(int i=1; i<N; i++){
        if(i<k) a[i]=1;
        else if(i==k) a[i]=2;
        else a[i]=(a[i-1]+a[i-k])%MOD;
        L[i]=L[i-1]+a[i];
        L[i]%=MOD;
    }
}

int main(){
    cin>> n>> k;
    xuly();
    for(int i=0; i<n; i++){
        int x,y;
        cin>> x>> y;
        if(L[y]-L[x-1]<0) printf("%d\n",L[y]-L[x-1]+MOD);
        else printf("%d\n",(L[y]-L[x-1])%MOD);
    }
    return 0;
}

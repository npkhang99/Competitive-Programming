#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int N=500009;

int n, a[N]={};
long long L[N]={};

void xuly(){
    if(n<3 || L[n-1]%3!=0){ printf("0\n"); return; }
    long long ans=0, d=0, x=L[n-1]/3;
    for(int i=0; i<n-1; i++){
        if(L[i]==x*2) ans+=d;
        if(L[i]==x) d+=1;
    }
    cout<< ans;
}

int main(){
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> a[i];
        if(i>0) L[i]=L[i-1]+a[i];
        else L[0]=a[0];
    }
    xuly();
    return 0;
}

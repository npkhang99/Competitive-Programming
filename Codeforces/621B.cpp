#include <iostream>
#include <stdio.h>
using namespace std;

const int N=1009;

int n, a[3*N]={}, b[3*N]={};

void doc(){
    cin>> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>> x>> y;
        a[x+y]+=1;
        b[x-y+N]+=1;
    }
}

int calc(int x){
    return x*(x-1)/2;
}

void xuly(){
    long long ans=0;
    for(int i=0; i<3*N; i++) ans+=calc(a[i])+calc(b[i]);
    cout<< ans;
}

int main(){
    doc();
    xuly();
    return 0;
}

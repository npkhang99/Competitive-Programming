#include <iostream>
#include <stdio.h>
#define fi "SZero.inp"
#define fo ""
using namespace std;

long n, a[100001], s[100001], vt[100000000003];
//---------------------------------------------------------
long tinh(long x){
    return(x+1000000);
}
//---------------------------------------------------------
void docfile(){
    cin>> n;
    for (long i=1; i<=n; i++){
        cin>> a[i];
    }
}
//---------------------------------------------------------
void xuat(long x, long y){
    cout<< x<< " "<< y;
}
//---------------------------------------------------------
void optimal(long& vtd, long& vtc, long x, long y){
    long size, sizet;
    size=vtc-vtc+1;
    sizet=y-x+1;
    if (size<sizet){
        vtd=x; vtc=y;
    }
}
//---------------------------------------------------------
void xuly(){
    long vtd,vtc,max;
    s[0]=0;
    for (long i=1; i<=n; i++){
        s[i]=s[i-1]+a[i];
        if (vt[tinh(s[i])]==0) vt[tinh(s[i])]=i;
        else optimal(vtd, vtc, vt[tinh(s[i])], i);
    }
    xuat(vtd,vtc);
}
//---------------------------------------------------------
int main(){
    freopen(fi, "r", stdin);
    freopen(fi, "w", stdout);
    docfile();
    xuly();
    return 0;
}
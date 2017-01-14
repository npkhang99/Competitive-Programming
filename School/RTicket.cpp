#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int a[N]={}, c1, c2, c3, l1, l2, l3, n, s, t;

void doc(){
    cin>> l1>> l2>> l3>> c1>> c2>> c3;
    cin>> n>> s>> t;
    if(s>t) swap(s,t);
    for(int i=1; i<n; i++) cin>> a[i];
}

int getCost(int i, int j){
    int t=a[j]-a[i];
    if(t<=0 || t>l3) return -1;
    if(t<=l1) return c1;
    else if(t<=l2) return c2;
    else if(t<=l3) return c3;
}

void xuly(){
    long long L[N];
    L[s-1]=0;
    for(int i=s; i<t; i++){
        L[i]=10E17;
        int j=i;
        while(--j>s-2 && getCost(j,i)>0) L[i]=min(L[i],L[j]+getCost(j,i));
    }
    cout<< L[t-1];
}

int main(){
    freopen("RTicket.inp","r",stdin);
    // freopen("RTicket.out","w",stdout);
    doc();
    xuly();
    return 0;
}

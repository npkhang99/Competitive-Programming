#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N=5009;

ii d[N];
int a[N], n, k;

void doc(){
    cin>> n>> k;
    for(int i=0; i<n; i++){
        d[i].first;
        d[i].second = i;
    }
}

void xuly(){
    sort(d,d+n,comp);
    for(int i=0; i<n; i++) a[d[i].second]=i/k;
    int L[N]={}, Lmax=0;
    for(int i=0; i<n; i++) printf("%d ",a[i]); cout<< endl;
    for(int i=0; i<n; i++){
        for(int j=i-1; j>=0; j--)
            if(a[i]>=a[j]) L[i]=max(L[i],L[j]+1);
        Lmax = max(Lmax, L[i]);
    }
    cout<< n-Lmax-1;
}

int main(){
    freopen("TeamK.inp","r",stdin);
    // freopen("TeamK.out","w",stdout);
    doc();
    xuly();
    return 0;
}

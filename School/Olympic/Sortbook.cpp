#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=1000009;

int a[N], n, k;

void doc(){
    cin>> n>> k;
    for(int i=0; i<k; i++){
        int x,y;
        cin>> x>> y;
        a[x]++; a[y+1]--;
    }
}

void xuly(){
    int bookNum=0;
    for(int i=0; i<n; i++){
        bookNum+=a[i];
        a[i]=bookNum;
    }
    sort(a,a+n);
    cout<< a[n/2];
}

int main(){
    freopen("Sortbook.inp","r",stdin);
    freopen("Sortbook.out","w",stdout);
    doc();
    xuly();
    return 0;
}

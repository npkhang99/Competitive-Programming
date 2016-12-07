#include <iostream>
#include <stdio.h>
#include <algorithm>
#define fi "Hermes.inp"
#define fo "Hermes.out"
using namespace std;

struct diem{
    int x,y;
}d[50000];
int a[50000], b[50000], n;
//---------------------------------------------------------
void xuly(){
    d[0].x=0; d[0].y=0;
    a[1]=b[1]=min(abs(d[1].x-d[0].x), abs(d[1].y-d[0].y));
    for (int i=2; i<=n; i++){
        a[i]=min(a[i-1],b[i-1]) + abs(d[i].x-d[i-1].x);
        b[i]=min(a[i-1],b[i-1]) + abs(d[i].y-d[i-1].y);
    }
}
//---------------------------------------------------------
int main(){
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> d[i].x>> d[i].y;
    xuly();
    cout<< min(a[n], b[n]);
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int N=109;
struct diem{
    int x, y;
}a[N];
int n;
double dtvuon;
//---------------------------------------------------------
void doc(){
    for(int i=1; i<=3; i++)
        cin>> a[i].x>> a[i].y;
    cin>> n;
    n+=4;
    for(int i=4; i<=n; i++)
        cin>> a[i].x>> a[i].y;
}
//---------------------------------------------------------
double dt(diem a, diem b, diem c){
    return abs((b.x-a.x)*(b.y+a.y) + (c.x-b.x)*(c.y+b.y) + (a.x-c.x)*(a.y+c.y))/2;
}
//---------------------------------------------------------
void xuly(){
    int dem;
    dtvuon=dt(a[1],a[2],a[3]);
    (cout<< fixed).precision(1);
    cout<< dtvuon<< endl;
    dem=0;
    for(int i=4; i<=n; i++){
        if(dt(a[1],a[2],a[i])+dt(a[1],a[i],a[3])+dt(a[i],a[2],a[3])==dtvuon) dem++;
    }
    (cout<< fixed).precision(0);cout<< dem;
}
//---------------------------------------------------------
int main(){
    freopen("Vuon.inp","r",stdin);
    freopen("Vuon.out","w",stdout);
    doc();
    xuly();
    return 0;
}

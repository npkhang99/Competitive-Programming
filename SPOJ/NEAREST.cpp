#include <iostream>
#include <algorithm>
#include <limits.h>
#include <math.h>
#define sqr(i) pow(i,2)
using namespace std;

const int N=100009;
struct diem{
    double x, y;
}a[N];
int n, b[N], c[N];
//---------------------------------------------------------
void doc(){
    cin>> n;
    for(int i=1; i<=n; i++){
        cin>> a[i].x>> a[i].y;
        b[i]=i;
    }
}
//---------------------------------------------------------
int comp(diem a, diem b){
    return a.x<b.x;
}
//---------------------------------------------------------
double cal(int i, int j){
    return sqrt(sqr(a[i].x-a[j].x) + sqr(a[i].y-a[j].y));
}
//---------------------------------------------------------
double absx(double x){
    if(x<0)return -x;
    else return x;
}
//---------------------------------------------------------
void merge(int l, int m, int r){
    int i,j,k;
    i=l; j=m+1; k=0;
    while(i<=m && j<=r)
        if(a[b[i]].y<a[b[j]].y){
            c[++k]=b[i];
            i++;
        }else{
            c[++k]=b[j];
            j++;
        }
    if(i<m) for(int p=i; p<=m; p++) c[++k]=b[p];
    else for(int p=j; p<=r; p++) c[++k]=b[p];
    for(int i=l; i<=r; i++) b[i]=c[i-l+1];
}
//---------------------------------------------------------
double findNearest(int l, int r){
    double d;
    if(l>=r) return INT_MAX;
    int m=(l+r)/2;
    d=min(findNearest(l,m) , findNearest(m+1,r));
    merge(l,m,r);
    int k=0;
    for(int i=l; i<=r; i++)
        if(absx(a[b[i]].x - a[m].x < d)) c[++k]=b[i];
    for(int i=1; i<=k-1; i++){
        int j=i+1;
        while(c[i]!=c[j] && j<=k && absx(a[c[i]].y - a[c[j]].y) < d){
            d=min(d, cal(c[i],c[j]));
            j++;
        }
    }
    return d;
}
//---------------------------------------------------------
int main(){
    doc();
    sort(a+1,a+n+1,comp);
    (cout<< fixed).precision(3);
    cout<< findNearest(1,n);
    return 0;
}

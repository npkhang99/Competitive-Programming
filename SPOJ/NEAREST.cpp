// SPOJ submission 17838693 (C++ 5) plaintext list. Status: AC, problem NEAREST, contest SPOJVN. By mansblacks (Khang), 2016-10-03 05:28:12.
#include <bits/stdc++.h>
using namespace std;

#define sqr(i) pow(i,2)
#define x first
#define y second

typedef pair<double,double> dd;

const int N=1000009;

int n, b[N], c[N];
dd a[N];
//---------------------------------------------------------
void doc(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%lf%lf",&a[i].x,&a[i].y);
        b[i]=i;
    }
}
//---------------------------------------------------------
double cal(int i, int j){
    return sqrt(sqr(a[i].x-a[j].x) + sqr(a[i].y-a[j].y));
}
//---------------------------------------------------------
void merge(int l, int m, int r){
    int i, j, k;
    i=l; j=m+1; k=0;

    while(i<=m && j<=r)
        if(a[b[i]].y < a[b[j]].y) c[++k]=b[i++];
        else c[++k]=b[j++];

    if(i<=m) for(int p=i; p<=m; p++) c[++k]=b[p];
    else for(int p=j; p<=r; p++) c[++k]=b[p];

    for(int i=l; i<=r; i++) b[i]=c[i-l+1];
}
//---------------------------------------------------------
double findNearest(int l, int r){
    double d;
    if(l>=r) return DBL_MAX;
    int m = (l+r)/2;
    d = min(findNearest(l,m) , findNearest(m+1,r));
    merge(l,m,r);
    int k=0;
    for(int i=l; i<=r; i++)
        if(abs(a[b[i]].x - a[m].x) < d) c[++k]=b[i];
    for(int i=1; i<=k-1; i++){
        int j=i+1;
        while(c[i]!=c[j] && j<=k && abs(a[c[i]].y - a[c[j]].y) < d){
            d=min(d, cal(c[i],c[j]));
            j++;
        }
    }
    return d;
}
//---------------------------------------------------------
int main(){
    doc();
    sort(a+1,a+n+1);
    printf("%.3lf\n",findNearest(1,n));
    return 0;
}

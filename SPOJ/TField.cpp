// SPOJ submission 17423184 (C++ 5) plaintext list. Status: AC, problem TFIELD, contest SPOJVN. By mansblacks (Khang), 2016-08-03 06:59:08.
#include <bits/stdc++.h>
using namespace std;

const int N=1100;
struct diem{
    long long x, y;
}a[N];
struct khoang{
    int mau, tt;
    long long dt;
}kh[N];
int n, k, dem[N]={};
//---------------------------------------------------------
void doc(){
    int m;
    cin>> n>> k;
    for(int i=1; i<=n; i++){
        kh[i].dt=0;
        cin>> m>> kh[i].mau;
        cin>> a[1].x>> a[1].y;
        a[m+1].x=a[1].x; a[m+1].y=a[1].y;
        for(int j=2; j<=m+1; j++){
            if(j!=m+1) cin>> a[j].x>> a[j].y;
            kh[i].dt=kh[i].dt + (a[j].x-a[j-1].x)*(a[j].y+a[j-1].y);
        }
        if(kh[i].dt<0) kh[i].dt=-kh[i].dt;
    }
}
//---------------------------------------------------------
int comp(khoang a, khoang b){
    return a.dt<b.dt;
}
//---------------------------------------------------------
void xuly(){
    int mau_max;
    long long kq;
    sort(kh+1,kh+n+1,comp);
    //for(int i=1; i<=n; i++) cout<< kh[i].dt<< " ";
    kq=0; kh[0].dt=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++) dem[j]=0;
        mau_max=0;
        for(int j=i; j<=n; j++){
            mau_max=max(mau_max, ++dem[kh[j].mau]);
            if(j-i+1-mau_max<=k) kq=max(kq, kh[j].dt-kh[i-1].dt);
        }
    }
    cout<< kq/2<< "."<< (kq%2)*5<< endl;
}
//---------------------------------------------------------
int main(){
    ios::sync_with_stdio(false);
    doc();
    xuly();
    return 0;
}
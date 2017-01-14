#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=509;

struct tank{
    int x,y;
} a[N];

int n;

void doc(){
    cin>> n;
    for(int i=0; i<n; i++) cin>> a[i].x>> a[i].y;
}

int comp1(tank a, tank b){
    return a.x < b.x;
}

int comp2(tank a, tank b){
    return a.y < b.y;
}

int abs(int x){
    return (x<0)? -x:x;
}

void xuly(){
    int ans=0;
    sort(a,a+n,comp1);
    for(int i=0; i<n; i++)
        if(a[i].x!=i+1){ ans+=abs(a[i].x - (i+1)); a[i].x=i+1; }
    sort(a,a+n,comp2);
    for(int i=0; i<n; i++)
        if(a[i].y!=i+1){ ans+=abs(a[i].y - (i+1)); a[i].y=i+1; }
    cout<< ans;
}

int main(){
    freopen("Tenki.inp","r",stdin);
    freopen("Tenki.out","w",stdout);
    doc();
    xuly();
    return 0;
}

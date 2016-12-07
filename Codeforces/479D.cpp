#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

const int N=100009;

int n, a[N], l, x, y, ableX=0, ableY=0;
set<int> b;

int main(){
    cin>> n>> l>> x>> y;
    for(int i=0; i<n; i++){
        cin>> a[i];
        b.insert(a[i]);
    }
    for(int i=1; i<n; i++){
        int toX = a[i]-x, toY = a[i]-y;
        if(b.find(toX)!=b.end()) ableX = 1;
        if(b.find(toY)!=b.end()) ableY = 1;
    }
    if(b.find(x+y)!=b.end()) ableY=1;
    else if(b.find(y-x)!=b.end()) ableX=1;
    printf("%d\n",2-ableX-ableY);
    if(!ableX) printf("%d ",x);
    if(!ableY) printf("%d ",y);
    return 0;
}

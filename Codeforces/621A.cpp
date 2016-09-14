#include <iostream>
#include <algorithm>
using namespace std;

const int N=100009;

#define long long long

int n, a[N];

void doc(){
    cin>> n;
    for(int i=0; i<n; i++) cin>> a[i];
}

void xuly(){
    sort(a,a+n);
    long t=0;
    for(int i=0; i<n; i++) t+=a[i];
    if(t%2==0){ cout<< t; return; }
    int i=0;
    while(t%2!=0){
        while(a[i]%2==0) i++;
        t-=a[i];
    }
    cout<< t;
}

int main(){
    doc();
    xuly();
    return 0;
}

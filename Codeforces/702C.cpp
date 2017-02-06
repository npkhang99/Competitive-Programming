#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;

int n, m;
long long a[N], b[N];

bool checkCover(long long x){
    int i=0, j=0;
    while(i<n && j<m){
        if(b[j]-x<=a[i] && b[j]+x>=a[i]) i+=1;
        else j+=1;
    }
    return i==n;
}

int main(){
    cin>> n>> m;
    for(int i=0; i<n; i++) cin>> a[i];
    for(int i=0; i<m; i++) cin>> b[i];
    long long l = 0, r = 2000000000, ans;
    while(l <= r){
        long long mid = (l + r) >> 1;
        if(checkCover(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout<< ans<< endl;
    return 0;
}

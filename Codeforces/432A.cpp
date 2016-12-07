#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=2009;

int n, a[N], k;

int main(){
    cin>> n>> k;
    for(int i=0; i<n; i++) cin>> a[i];
    sort(a,a+n);
    int cnt=0;
    for(int i=0; i<n; i++)
        if(a[i]<=5-k) cnt+=1;
    cout<< (int)cnt/3;
    return 0;
}

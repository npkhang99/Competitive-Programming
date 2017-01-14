#include <bits/stdc++.h>
using namespace std;

const int N=2000009;

int n, a[N]={};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> n, n){
        for(int i=0; i<n; i++) cin>> a[i];
        sort(a,a+n);
        cout<< a[0];
        for(int i=1; i<n; i++) cout<< " "<< a[i];
        cout<< '\n';
    }
    return 0;
}

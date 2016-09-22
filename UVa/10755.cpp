#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=20*20*20+9;

int T, n, a[N]={}, l, w, h;
long long ans = 0, temp = 0;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> T;
    for(int i=0; i<T; i++){
        cin>> l>> h>> w;
        n = l*h*w;
        ans = 0; temp = 0;
        for(int i=0; i<n; i++){
            cin>> a[i];
            ans += a[i];
        }
        for(int i=0; i<n; i++){
            temp += a[i];
            ans = max(temp,ans);
            if(temp<0) temp = 0;
        }
        cout<< ans<< "\n\n";
    }
    return 0;
}

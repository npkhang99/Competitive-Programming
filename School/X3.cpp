#include <bits/stdc++.h>
using namespace std;

const int N=1000009;

int n;
long long a[N]={};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("X3.inp","r",stdin);
    freopen("X3.out","w",stdout);
    cin>> n;
    for(int i=0; i<n; i++) cin>> a[i];

    long long ans = 0;
    for(long long i=0; i<=20; i++){
        long long cnt = 0;
        for(long long j=0; j<n; j++)
            if((a[j] >> i) & 1) cnt += 1;
        ans += cnt * (n - cnt) * (1 << i);
    }
    cout<< ans<< '\n';
    return 0;
}

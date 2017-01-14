#include <bits/stdc++.h>
using namespace std;

const int N = 19;

int T, n, a[N]={};

int main(){
    scanf("%d",&T);
    for(int t=0; t<T;){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int penalty = 0, ans = 0, c_time = 0;
        sort(a,a+n);
        for(int i=0; i<n && c_time + a[i] <= 300; i++)
            penalty += c_time + a[i], c_time += a[i], ans += 1;
        printf("Case %d: %d %d\n",++t,ans,penalty);
    }
    return 0;
}

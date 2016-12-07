#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, a[N]={}, b[N]={};

long long cycle(int i, int r, int d){
    if(b[i] && i == r && d%2 == 1) return d;
    if(b[i] && i == r) return d/2;
    if(b[i]) return 1e9;
    b[i] = true;
    return cycle(a[i],r,d+1);
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    long long ans = 1;
    for(int i=1; i<=n; i++){
        memset(b,0,sizeof b);
        long long t = cycle(i,i,0);
        if(t == 1e9){
            ans = -1;
            break;
        }
        ans = ans * (t/__gcd(ans,t));
    }
    printf("%lld\n",ans);
    return 0;
}

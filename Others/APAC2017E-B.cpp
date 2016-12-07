// Google CodeJam
#include <bits/stdc++.h>
using namespace std;

int T, t, n;

int test(int base){
    int a = n;
    while(a){
        if(a % base != 1) return 0;
        a /= base;
    }
    return base;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ans = 0;
        for(int i=2; i<=1000; i++){
            ans = test(i);
            if(ans) break;
        }
        printf("Case #%d: %d\n",++t,ans);
    }
    return 0;
}

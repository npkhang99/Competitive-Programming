// Google CodeJam
#include <bits/stdc++.h>
using namespace std;

int t=0, T, n, d, ans = 0;

void btrack(int last, int left, int first){
    if(left == 0){ ans += 1; return; }
    if(left < last) return;
    for(int i=last; i<=first+2; i++)
        btrack(i, left-i, first);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&d);
        ans = 0;
        for(int i=d; i<=n; i+=d)
            btrack(i, n-i, i);
        printf("Case #%d: %d\n",++t,ans);
    }
    return 0;
}

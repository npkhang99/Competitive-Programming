#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int T, l, n;
queue<int> ql, qr;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&l,&n);
        l *= 100;
        for(int i=0; i<n; i++){
            char st[10]; int x;
            scanf("%d%s",&x,st);
            if(strcmp(st,"right") == 0) qr.push(x);
            else ql.push(x);
        }

        int ans = 0, currBank = -1;
        while(!ql.empty() || !qr.empty()){
            int w = 0;
            if(currBank == -1){
                while(!ql.empty() && ql.front() + w <= l) w += ql.front(), ql.pop();
                ans += 1, currBank = 1;
                continue;
            }
            while(!qr.empty() && qr.front() + w <= l) w += qr.front(), qr.pop();
            ans += 1, currBank = -1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

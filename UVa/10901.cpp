#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

int T, n, t, m, a[10009]={};
queue<ii> ql, qr;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&t,&m);
        for(int i=0; i<m; i++){
            char bank[10]; int x;
            scanf("%d%s",&x,bank);
            if(strcmp(bank,"right") == 0) qr.push(ii(x,i));
            else ql.push(ii(x,i));
        }

        int tt = ql.front().first, cbank = -1;
        if((!qr.empty() && !ql.empty() && qr.front().first < ql.front().first)
            || (!qr.empty() && ql.empty())) tt = qr.front().first+t, cbank = 1;
        while(!ql.empty() || !qr.empty()){
            // printf("%d %d\n",tt,cbank);
            int w = 0;
            if(cbank == -1){
                while(!ql.empty() && tt >= ql.front().first && w+1 <= n)
                    a[ql.front().second] = tt + t, w+=1, ql.pop();

                tt += t; cbank = 1;
                if(!qr.empty() && qr.front().first <= tt) continue;
                if((qr.empty() && !ql.empty()) ||
                    (!qr.empty() && !ql.empty() && qr.front().first < ql.front().first))
                    tt += (ql)
                continue;
            }
            while(!qr.empty() && tt >= qr.front().first && w+1 <= n)
                a[qr.front().second] = tt + t, w+=1, qr.pop();

        }

        for(int i=0; i<m; i++) printf("%d\n",a[i]);
        if(T) printf("\n");
    }
    return 0;
}

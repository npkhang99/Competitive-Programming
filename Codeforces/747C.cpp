#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, q, a[N]={};
vector<int> server;

int main(){
    scanf("%d%d",&n,&q);
    for(int i=0; i<q; i++){
        int t, k, d; scanf("%d%d%d",&t,&k,&d);
        int free = 0;
        server.clear();
        for(int i=1; i<=n; i++)
            if(a[i] <= t){
                free++, server.push_back(i);
                if(free == k) break;
            }

        if(free < k){
            printf("-1\n");
            continue;
        }
        int ans = 0;
        for(int i=0; i<server.size(); i++){
            ans += server[i];
            a[server[i]] = t + d;
        }
        printf("%d\n",ans);
    }
    return 0;
}

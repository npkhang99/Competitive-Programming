// CodeChef
#include <bits/stdc++.h>
using namespace std;

const int N = 29;

int n, m, f[N]={};

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            f[i] = 0;
        for(int i=0; i<m; i++){
            int x, y; scanf("%d%d",&x,&y); x-=1; y-=1;
            f[x] |= 1 << y;
            f[y] |= 1 << x;
        }

        int ans = 1e9;
        for(int i=1; i < (1 << n); i++){
            if(__builtin_popcount(i) >= ans) continue;
            int mask = i;
            bool all = false;
            for(int j=0; j<n; j++)
                if(1 & (i >> j)){
                    mask |= f[j];
                    if(mask == (1 << n) - 1){
                        all = true;
                        break;
                    }
                }
            if(all) ans = min(__builtin_popcount(i), ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}

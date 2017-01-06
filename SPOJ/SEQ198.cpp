#include <bits/stdc++.h>
using namespace std;

const int N = 2009;

int n, a[N]={};
vector<int> b[N];

bool seq(int x, int y){
    return x - y == 1 || x - y == 9 || x - y == 8;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    bool flag = false;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(seq(a[i],a[j])){
                flag = true;
                break;
            }

    if(!flag){
        printf("0\n");
        return 0;
    }

    int ans = 1e9;
    for(int mask = 1; mask < (1 << n); mask++){
        flag = false;
        for(int i=0; i<n; i++)
            if(!((mask >> i) & 1)){
                for(int j=0; j<n; j++)
                    if(!((mask >> i) & 1) && seq(a[i], a[j])){
                        flag = true;
                        break;
                    }
                if(flag) break;
            }
        if(!flag) ans = min(ans, __builtin_popcount(mask));
        if(ans == 1) break;
    }
    printf("%d\n",ans);
    return 0;
}

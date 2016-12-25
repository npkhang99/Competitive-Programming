#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 20;

int n;
ii a[N]={};
double dp[1 << N]={};

double sqr(int x){
    return x*x;
}

double dist(int i, int j){
    return sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y));
}

int main(){
    int T = 0;
    while(scanf("%d",&n), n){
        for(int i=0; i<2*n; i++)
            scanf(" %*s%d%d", &a[i].x, &a[i].y);

        for(int mask = 3; mask < (1 << (2*n)); mask++){
            if(__builtin_popcount(mask) % 2 == 1) continue;
            dp[mask] = 1e9;
            for(int i=0; i<2*n; i++)
                if(1 & (mask >> i)){
                    int pre = mask - (1 << i);
                    for(int j=0; j<2*n; j++)
                        if(1 & (pre >> j)){
                            int _pre = pre - (1 << j);
                            dp[mask] = min(dp[mask], dp[_pre] + dist(i,j));
                        }
                }
            // fprintf(stderr, "%d %.2lf\n", mask, dp[mask]);
        }

        printf("Case %d: %.2lf\n", ++T, dp[(1<<(2*n))-1]);
    }
    return 0;
}

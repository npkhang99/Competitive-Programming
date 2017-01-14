#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define BIT(i,x) ((x >> i) & 1)

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 20;

int n, fin, T = 0;
ii a[N]={};
double dp[1 << N]={};

double sqr(int x){
    return x*x;
}

double dist(int i, int j){
    return sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y));
}

void solution1(){ // bottom - up
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
    }

    printf("Case %d: %.2lf\n", ++T, dp[(1<<(2*n))-1]);
}

double matching(int mask){
    if(dp[mask] > -0.5) return dp[mask];
    if(mask == fin) return dp[mask] = 0;

    double ans = 1e18;
    int p1, p2;
    for(p1=0; p1<2*n; p1++)
        if(!BIT(p1,mask)) break;

    for(p2=p1+1; p2<2*n; p2++)
        if(!BIT(p2,mask)) ans = min(ans, dist(p1,p2) + matching(mask | (1 << p1) | (1 << p2)));
    return dp[mask] = ans;
}

void solution2(){ // top - down
    for(int i=0; i < (1 << (2*n)); i++)
        dp[i] = -1;
    fin = (1 << (2*n)) - 1;
    printf("Case %d: %.2lf\n", ++T, matching(0));
}

int main(){
    while(scanf("%d",&n), n){
        for(int i=0; i<2*n; i++)
            scanf(" %*s%d%d", &a[i].x, &a[i].y);

        // solution1();
        solution2();
    }
    return 0;
}

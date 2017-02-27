// HackerRank - Week of Code 27 - Hackonacci Matrix Rotations
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2009;
const int BASE = 2;

int n, q, a[N][N]={}, b[N][N]={}, c[N][N]={}, ans[4]={};
map<ll, int> memo;

void rotate(){
    for(int i=n; i>=1; i--) for(int j=1; j<=n; j++)
        b[j][n-i+1] = a[i][j];

    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
        a[i][j] = b[i][j];
}

int hack(ll x){
    if(x < 4) return x;
    if(memo[x]) return memo[x];
    return memo[x] = (hack(x-1) + 2*hack(x-2) + 3*hack(x-3)) % BASE;
}

int main(){
    scanf("%d%d",&n,&q);
    for(ll i=0; i<=7; i++){
        for(ll j=0; j<=7; j++)
            if(!i || !j) a[i][j] = 1;
            else a[i][j] = hack(i*i*j*j);
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            a[i][j] = a[i%7][j%7];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            c[i][j] = a[i][j];

    for(int r=1; r<4; r++){
        rotate();
        int x = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                x += abs(c[i][j] - a[i][j]);
        ans[r] = x;
    }

    for(int i=0; i<q; i++){
        int x; scanf("%d",&x);
        printf("%d\n",ans[(x % 360) / 90]);
    }
    return 0;
}

// CodeChef
#include <bits/stdc++.h>
using namespace std;

const int N = 1009;

int n, m, q, a[N][N]={}, dp[N][N]={}, b[N][N]={};

void createDP(int x, int y, int median){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j] >= median) b[i][j] = 1;
            else b[i][j] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            dp[i][j] = b[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
}

bool check(int x, int y){
    for(int i=x; i<=n; i++)
        for(int j=y; j<=m; j++)
            if(dp[i][j] - dp[i][j-y] - dp[i-x][j] + dp[i-x][j-y] > (x*y)/2)
                return true;
    return false;
}

void solve(int x, int y){
    int l = 1, r = 10E6, ans = 0;
    while(l <= r){
        int mid  = (l+r) / 2;
        createDP(x,y,mid);
        if(check(x,y)){
            ans = mid;
            l = mid+1;
        }else r = mid - 1;
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);

    for(int query = 0; query < q; query++){
        int x,y; scanf("%d %d",&x,&y);
        solve(x,y);
    }
    return 0;
}

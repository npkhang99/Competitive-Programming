// HackerRank - Flipping the Matrix
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 128 + 9;

int n, a[N][N]={};

int find(int x, int y){
    int temp = 0;
    temp = max(temp, a[x][y]);
    temp = max(temp, a[x][2*n-y+1]);
    temp = max(temp, a[2*n-x+1][y]);
    temp = max(temp, a[2*n-x+1][2*n-y+1]);
    return temp;
}

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        for(int i=1; i<=2*n; i++) for(int j=1; j<=2*n; j++)
            scanf("%d",&a[i][j]);

        int ans = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                ans += find(i,j);

        printf("%d\n",ans);
    }
    return 0;
}

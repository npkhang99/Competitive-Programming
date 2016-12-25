#include <bits/stdc++.h>
using namespace std;

const int N = 29;

int n, m, floyd[N][N]={};
char member[N][19]={};

int main(){
    int T = 0;
    while(scanf("%d%d",&n,&m), n || m){
        for(int i=1; i<=n; i++)
            scanf(" %s",member[i]);
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i!=j) floyd[i][j] = 1e9;

        for(int i=0; i<m; i++){
            int x, y, v; scanf("%d%d%d",&x,&y,&v);
            floyd[x][y] = floyd[y][x] = v;
        }

        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

        int ans = 1e9, p=0;
        for(int i=1; i<=n; i++){
            int temp = 0;
            for(int j=1; j<=n; j++)
                temp += floyd[j][i];
            if(temp < ans){
                ans = temp;
                p = i;
            }
        }

        printf("Case #%d : %s\n", ++T, member[p]);
    }
    return 0;
}

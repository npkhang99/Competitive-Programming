#include <bits/stdc++.h>
using namespace std;

const int N = 19;

int n = 4, a[N][N]={};
char board[N][N];

int max(int a, int b, int c){
    return max(a, max(b, c));
}

bool win(int x, int y){
    return  (a[x][y] == 1 && ((a[x+1][y] == 0 && a[x+2][y] == 1) || (a[x+1][y] == 1 && a[x+2][y] == 0))) ||
            (a[x][y] == 1 && ((a[x+1][y+1] == 0 && a[x+2][y+2] == 1) || (a[x+1][y+1] == 1 && a[x+2][y+2] == 0))) ||
            (a[x][y] == 1 && ((a[x][y+1] == 0 && a[x][y+2] == 1) || (a[x][y+1] == 1 && a[x][y+2] == 0))) ||
            (a[x][y] == 0 && a[x+1][y] == 1 && a[x+2][y] == 1) ||
            (a[x][y] == 0 && a[x+1][y+1] == 1 && a[x+2][y+2] == 1) ||
            (a[x][y] == 0 && a[x][y+1] == 1 && a[x][y+2] == 1) ||
            (a[x][y] == 1 && ((a[x+1][y-1] == 0 && a[x+2][y-2] == 1) || (a[x+1][y-1] == 1 && a[x+2][y-2] == 0))) ||
            (a[x][y] == 0 && a[x+1][y-1] == 1 && a[x+2][y-2] == 1);
}

int main(){
    while(~scanf("%s %s %s %s", board[1]+1, board[2]+1, board[3]+1, board[4]+1)){
        memset(a, -1, sizeof a);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(board[i][j] == 'x') a[i][j] = 1;
                else if(board[i][j] == 'o') a[i][j] = -1;
                else a[i][j] = 0;
    
        bool flag = false;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(win(i,j)) flag = true;
    
        if(flag) printf("YES\n");
        else printf("NO\n");
    }    
    return 0;
}

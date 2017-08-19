#include <bits/stdc++.h>
using namespace std;

#define left aowhef92hr9f2g3
#define right x2h39r81h239r1y

typedef pair<int,int> ii;

const int N = 109;

int n, m, cnt = 0, left = 0, right = 0, top = 0, bot = 0;
char a[N][N]={};

int prep(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != 'B') continue;
            cnt++;
            if(left == 0 || j < left) left = j;
            if(j > right) right = j;
            if(top == 0 || i < top) top = i;
            if(i > bot) bot = i;
        }
    }
    return max(right - left + 1, bot - top + 1);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf(" %s", a[i]+1);
    }

    int a = prep();
    if(cnt < 2){
        printf("%d\n", cnt == 0);
        return 0;
    }else if(a > n || a > m) printf("-1\n");
    else printf("%d\n", a * a - cnt);
    return 0;
}

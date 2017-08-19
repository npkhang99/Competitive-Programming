#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, m, k, a[N][N]={};

int main(){
    scanf("%d %d %d", &n, &m, &k);
    int i = 1, j = 1;
    for(int c = 1; c <= k; c++){
        int cnt; scanf("%d", &cnt);
        int x = 0;
        while(cnt){
            if(i % 2 == 1){
                for(; j <= m && cnt; j++) a[i][j] = c, cnt--;
                if(cnt || j == m+1){ i++; j--; continue; }
            }
            if(i % 2 == 0){
                for(; j >= 1 && cnt; j--) a[i][j] = c, cnt--;
                if(cnt || j == 0){ i++; j++; continue; }
            }
        }
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            printf("%d%c", a[i][j], " \n"[j == m]);
        }
    }
    return 0;
}

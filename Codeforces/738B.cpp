#include <cstdio>
using namespace std;

const int N = 1009;

int n, m, a[N][N], b[N][N], c[N][N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            scanf("%d",&a[i][j]);
            b[i][j] = b[i][j-1] + a[i][j];
            c[i][j] = c[i-1][j] + a[i][j];
        }
    long long ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(!a[i][j]){
                // printf("%d %d - %d\n",i,j,(b[i][j] > 0) + (b[i][m] - b[i][j] > 0) + (c[i][j] > 0) + (c[n][j] - c[i][j] > 0));
                ans += (b[i][j] > 0) + (b[i][m] - b[i][j] > 0) + (c[i][j] > 0) + (c[n][j] - c[i][j] > 0);
            }
    printf("%lld\n",ans);
    return 0;
}

#include <stdio.h>
using namespace std;

const int N=109;

int n, a[N][N]={}, L[N][N]={};

int max(int a, int b){ return a>b? a:b; }

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) scanf("%d",&a[i][j]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            L[i][j] = L[i-1][j] + L[i][j-1] - L[i-1][j-1] + a[i][j];

    int ans = -10E8;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int ii=i; ii<=n; ii++)
                for(int jj=j; jj<=n; jj++)
                    ans = max(ans,L[ii][jj] - L[i-1][jj] - L[ii][j-1] + L[i-1][j-1]);

    printf("%d\n",ans);
    return 0;
}

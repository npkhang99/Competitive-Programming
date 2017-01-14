#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=109;

int n, a[N]={}, c[N]={}, m, x;

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        c[x] = i+1;
    }

    while(scanf("%d",&x)!=EOF){
        a[x] = 1;
        for(int i=2; i<=n; i++)
            scanf("%d",&x), a[x] = i;

        int L[N][N]={};
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(a[i] == c[j]) L[i][j] = L[i-1][j-1] + 1;
                else L[i][j] = max(L[i-1][j], L[i][j-1]);
        printf("%d\n",L[n][n]);
    }
    return 0;
}

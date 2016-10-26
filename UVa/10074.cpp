#include <cstdio>
#include <algorithm>
using namespace std;

const int N=109;

int n, m, a[N][N]={}, L[N][N]={};

int main(){
    while(scanf("%d%d",&n,&m), n || m){
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]), L[i][j] = L[i][j-1] + a[i][j];

        int ans = 0;
        for(int l=1; l<=m; l++) for(int r=l; r<=m; r++){
            int temp = 0;
            for(int i=1; i<=n; i++){
                if(L[i][l] == L[i][r] && !a[i][l] && !a[i][r]) temp += r-l+1;
                else temp = 0;
                ans = max(ans,temp);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

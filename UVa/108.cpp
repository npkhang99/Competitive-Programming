#include <cstdio>
using namespace std;

const int N=109;

int n, a[N][N]={}, L[N][N]={};

int max(int a, int b){ return a>b? a:b; }

int main(){
    while(~scanf("%d",&n)){
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&a[i][j]), L[i][j] = L[i][j-1] + a[i][j];
    
        int ans = -10E8;
        for(int l=1; l<=n; l++) for(int r=l; r<=n; r++){
            int temp = 0;
            for(int row = 1; row <= n; row++){
                temp += L[row][r] - L[row][l-1];
                ans = max(ans,temp);
                if(temp < 0) temp = 0;
            }
        }
    
        printf("%d\n",ans);
    }    
    return 0;
}

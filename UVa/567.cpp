#include <cstdio>
using namespace std;

int min(int a, int b){ return (a<b)?a:b; }

const int N=29;

int a[N][N], ans[N][N], n, T=0;

void init(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(i==j) a[i][j]=0;
            else a[i][j] = 10E3;
}

void floyd(){
    for(int k=0; k<20; k++)
        for(int i=0; i<20; i++)
            for(int j=0; j<20; j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}

int main(){
    int x, y;
    while(~scanf("%d",&n)){
        init();
        for(int i=0; i<n; i++){
            scanf("%d",&x); x-=1;
            a[x][0] = a[0][x] = 1;
        }
        for(int i=1; i<19; i++){
            scanf("%d",&n);
            for(int j=0; j<n; j++){
                scanf("%d",&x); x-=1;
                a[x][i] = a[i][x] = 1;
            }
        }
        
        floyd();
        
        printf("Test Set #%d\n",++T);
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d%d",&x,&y);
            printf("%2d to %2d: %d\n",x,y,a[x-1][y-1]);
        }
        printf("\n");
    }
    return 0;
}

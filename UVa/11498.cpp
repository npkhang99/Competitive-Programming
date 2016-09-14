#include <stdio.h>
using namespace std;

int n, x0, y0, x, y;

int main(){
    while(scanf("%d\n",&n), n){
        scanf("%d %d\n",&x0,&y0);
        for(int i=0; i<n; i++){
            scanf("%d %d\n",&x,&y);
            if(x-x0==0 || y-y0==0) printf("divisa\n");
            else if(x-x0>0 && y-y0>0) printf("NE\n");
            else if(x-x0<0 && y-y0>0) printf("NO\n");
            else if(x-x0<0 && y-y0<0) printf("SO\n");
            else if(x-x0>0 && y-y0<0) printf("SE\n");
        }
    }
    return 0;
}

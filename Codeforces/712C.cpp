#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int x, y, a[5]={}, ans=0;

int main(){
    scanf("%d%d",&x,&y);
    a[1] = a[2] = a[3] = y;
    while(a[1]-x || a[2]-x || a[3]-x){
        sort(a+1,a+4);
        a[1] = min(x,a[3]+a[2]-1);
        ans+=1;
    }
    printf("%d\n",ans);
    return 0;
}

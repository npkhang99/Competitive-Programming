#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;

int m, a[N]={}, b[N]={}, colNum=0, rowNum=0;
long long n;

int main(){
    scanf("%lld%d\n",&n,&m);
    long long left = n*n;
    for(int i=0; i<m; i++){
        int x,y; scanf("%d%d\n",&x,&y);
        if(!a[x]){ left-=n-rowNum; colNum+=1; }
        if(!b[y]){ left-=n-colNum; rowNum+=1; }
        // if(!a[x] && !b[y]) left+=1;
        a[x] = b[y] = 1;
        printf("%lld ",left);
    }
    printf("\n");
    return 0;
}

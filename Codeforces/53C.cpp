#include <stdio.h>
using namespace std;

int n;

int main(){
    scanf("%d",&n);
    int i=0, j=n+1;
    while(++i<=--j)
        if(i<j) printf("%d %d ",i,j);
        else printf("%d ",i);
    return 0;
}
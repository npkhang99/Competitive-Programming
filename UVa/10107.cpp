#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int x, n=0, a[10009]={};

int main(){
    while(scanf("%d",&x)!=EOF){
        a[n++] = x; sort(a,a+n);
        int i = n/2, j = n-1-i;
        printf("%d\n",(a[i]+a[j])/2);
    }
    return 0;
}

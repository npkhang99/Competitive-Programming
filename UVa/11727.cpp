#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[3];

int main(){
    scanf("%d\n",&n);
    for(int i=0; i<n;){
        scanf("%d %d %d\n",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        printf("Case %d: %d\n",++i,a[1]);
    }
    return 0;
}

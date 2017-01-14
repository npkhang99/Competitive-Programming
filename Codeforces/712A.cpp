#include <stdio.h>
using namespace std;

const int N=100009;

int n, a[N], b[N];

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    b[n] = a[n];
    for(int i=n-1; i>0; i--) b[i] = a[i]+a[i+1];
    for(int i=1; i<=n; i++) printf("%d ",b[i]);
    printf("\n");
    return 0;
}

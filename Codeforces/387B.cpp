#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=3009;

int n, m, a[N], b[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<m; i++) scanf("%d",&b[i]);
    sort(a,a+n); sort(b,b+m);
    int i=0, j=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){ i+=1; j+=1; continue; }
        while(j<m && a[i]>b[j]) j+=1;
    }
    printf("%d\n",n-i);
    return 0;
}
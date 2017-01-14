#include <stdio.h>
#include <algorithm>
using namespace std;

int n, i, j;
float a[500009], t;

int main(){
    freopen("sort3mb.inp","r",stdin);
    scanf("%d\n",&n);
    for(i=0; i<n/2; i++) scanf("%f",&a[i]);
    sort(a,a+n/2);
    freopen("temp","w",stdout);
    for(i=0; i<max(n/2,n-n/2); i++){
        if(i<n/2) printf("%.2f ",a[i]);
        if(i<n-n/2) scanf("%f",&a[i]);
    }
    // for(int i=0; i<n-n/2; i++) scanf("%f",&a[i]);
    sort(a,a+n-n/2);
    freopen("temp","r",stdin);
    freopen("sort3mb.out","w",stdout);
    i=0; j=0;
    if(i<n/2) scanf("%f",&t);
    for(j=0; j<n-n/2 && i<n/2 && n/2>0;)
        if(t<a[j]){
            printf("%.2f ",t);
            scanf("%f",&t);
            i+=1;
        }
        else printf("%.2f ",a[j++]);
    while(i<n/2){ printf("%.2f ",t); scanf("%f",&t); i+=1; }
    while(j<n-n/2) printf("%.2f ",a[j++]);
    return 0;
}

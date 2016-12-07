#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;

struct answer{
    int soldier, vest;
}ans[N];

int n, a[N], b[N], m, x, y;

void xuly(){
    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(a[i]-x<=b[j] && a[i]+y>=b[j]){
            i+=1; j+=1;
            ans[k].soldier = i;
            ans[k].vest = j;
            k+=1;
        }
        if(a[i]-x>b[j]){ j+=1; continue; }
        if(a[i]+y<b[j]){ i+=1; continue; }
    }
    printf("%d\n",k);
    for(int i=0; i<k; i++)
        printf("%d %d\n",ans[i].soldier,ans[i].vest);
}

int main(){
    cin>> n>> m>> x>> y;
    for(int i=0; i<n; i++) cin>> a[i];
    for(int i=0; i<m; i++) cin>> b[i];
    xuly();
    return 0;
}

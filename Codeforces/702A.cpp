#include <stdio.h>
using namespace std;

const int N=100009;

int n, a[N];

int main(){
    scanf("%d %d ",&n,&a[0]);
    int ans = 1, t = 1;
    for(int i=1; i<n; i++){
        scanf("%d",&a[i]);
        if(a[i]>a[i-1]) t+=1;
        else t = 1;
        ans = ans<t? t:ans;
    }
    printf("%d\n",ans);
    return 0;
}

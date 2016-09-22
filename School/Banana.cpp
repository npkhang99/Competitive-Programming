#include <stdio.h>
using namespace std;

const int N=5009;

int n, a[N]={};

int main(){
    // freopen("Banana.inp","r",stdin);
    // freopen("Banana.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    int ans = 1, i = 1;
    long long curr = 0, last = a[0];
    while(i<n){
        while(i<n && curr < last) curr+=a[i++];
        if(curr>=last) ans+=1, last = curr, curr = 0;
    }
    printf("%d\n",ans);
    return 0;
}

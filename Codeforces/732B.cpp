#include <cstdio>
using namespace std;

const int N=509;

int n, a[N]={}, ans = 0, k;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);

    int flag = 1;
    for(int i=0; i<n-1; i++)
        if(a[i] + a[i+1] < k){ flag = 0; break; }
    if(flag){
        printf("0\n");
        for(int i=0; i<n; i++) printf("%d ",a[i]);
        printf("\n");
        return 0;
    }
    a[n] = k;

    for(int i=1; i<n; i++){
        if(a[i-1] + a[i] >= k) continue;
        while(a[i-1] + a[i] < k) a[i]+=1, ans+=1;
    }

    printf("%d\n",ans);
    for(int i=0; i<n; i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

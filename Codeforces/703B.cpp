#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;

int n, k, a[N]={};
long long sum=0, ans=0;
bool b[N]={};

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    a[0] = a[n]; a[n+1] = a[1];
    for(int i=0; i<k; i++){
        int x; scanf("%d",&x);
        b[x] = 1;
    }
    for(int i=1; i<=n; i++){
        if(!b[i]){ ans+=a[i]*a[i-1]; continue; }
        if(i==1 && !b[n]) ans+=a[i]*(sum-a[i]-a[i+1]);
        else if(i!=1 && !b[i-1]) ans+=a[i]*(sum-a[i]-a[i+1]);
        else ans+=a[i]*(sum-a[i]-a[i+1]+a[i-1]);
        sum-=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}

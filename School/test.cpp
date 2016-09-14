#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N=100009;

typedef pair<int,int> ii;

int n, d;
long long b[N]={};
ii a[N];

int main(){
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&a[i].fi,&a[i].se);
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) b[i] = b[i-1]+a[i].se;
    long long ans=0;
    for(int l=1,r=1; r<=n; r++){
        while(a[r].fi-a[l].fi >= d) l+=1;
        // printf("%d %d\n",l,r);
        ans = max(ans,b[r]-b[l-1]);
    }
    printf("%I64d\n",ans);
    return 0;
}

#include <stdio.h>
using namespace std;

long long n, m;

bool isInRange(long long lo, long long hi){
    return m>=lo && m<=hi;
}

int main(){
    // freopen("Square.inp","r",stdin);
    // freopen("Square.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(m==1 || m==n*n){
        if(m==1) printf("1 1\n");
        else printf("%lld %lld\n",n,n);
        return 0;
    }
    // first half
    long long lo=0, hi=0, diff=1;
    for(int i=1; i<=n; i++){
        lo = hi+1, hi = lo+diff-1, diff+=1;
        if(isInRange(lo,hi)){
            int row = hi-m+1, col = m-lo+1;
            printf("%d %d\n",row,col);
            return 0;
        }
    }
    // second half
    diff=n-1;
    for(int i=2; i<=n; i++){
        lo = hi+1, hi = lo+diff-1, diff-=1;
        if(isInRange(lo,hi)){
            int row = n-m+lo, col = n-hi+m;
            printf("%d %d\n",row,col);
            return 0;
        }
    }
    return 0;
}

#include <stdio.h>

long long n,m;

long long GCD(long long a, long long b){
    while(b!=0){
        long long r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    // freopen("SHARE.inp","r",stdin);
    // freopen("SHARE.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",m-GCD(n,m));
    return 0;
}
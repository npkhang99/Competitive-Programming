#include <iostream>
#include <stdio.h>
using namespace std;

#define MOD 10000007

int T, a, b, c, d, e, f, n;

int main(){
    scanf("%d",&T);
    for(int cases=0; cases<T; cases++){
        scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&n);
        a%=MOD; b%=MOD; c%=MOD; d%=MOD; e%=MOD; f%=MOD;
        int ans=0;
        switch(n){
            case(0): ans=a; break;
            case(1): ans=b; break;
            case(2): ans=c; break;
            case(3): ans=d; break;
            case(4): ans=e; break;
            case(5): ans=f; break;
            default: ans=(a+b+c+d+e+f)%MOD;
        }
        for(int i=0; i<n-6; i++){
            a=b;b=c;c=d;d=e;e=f;f=ans;
            ans=(a+b+c+d+e+f)%MOD;
        }
        printf("Case %d: %d\n",cases+1,ans);
    }
    return 0;
}

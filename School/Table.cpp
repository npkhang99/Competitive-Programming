#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

const double PI = 4*atan(1);

long long n, R, r;

int main(){
    // freopen("Table.inp","r",stdin);
    // freopen("Table.out","w",stdout);
    scanf("%lld%lld%lld",&n,&R,&r);
    long long r1 = R-r;
    if(!n){
        printf("YES\n");
        return 0;
    }
    if(r1 <= 0){
        if(r1 == 0 && n==1) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    double alpha = asin(double(r) / double(r1)) * 2;
    alpha *= n;
    printf("%.36lf\n%.36lf\n",alpha,2*PI);
    if(alpha <= 2*PI) printf("YES\n");
    else printf("NO\n");
    return 0;
}

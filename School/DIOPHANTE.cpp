#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int a, b, c;
long long x, y;

int diophante(int a, int b, long long &x, long long &y){
    long long xa=1, ya=0, xb=0, yb=1;
    while(b!=0){
        int q = a/b,
            r = a - b*q;
        int xr = xa - q*xb,
            yr = ya - q*yb;
        a = b; xa = xb; ya = yb;
        b = r; xb = xr; yb = yr;
    }
    x = xa*c/a; y = ya*c/a;
    return a;
}

int main(){
    // freopen("DIOPHANTE.inp","r",stdin);
    // freopen("DIOPHANTE.out","w",stdout);
    scanf("%d%d%d",&a,&b,&c);
    int d = diophante(a,b,x,y);
    if(c%d!=0){ printf("0\n"); exit(0); }
    long long xt=x, yt=y, p = b/d, q = a/d, k;
    int ans=0;
    // printf("%lld %lld\n",x,y);
    k = -x/p;
    while(y-k*q>0) if(x+(k++)*p>0) ans+=1;
    k = -y/q;
    while(x-k*p>0) if(y-(k++)*q>0) ans+=1;
    printf("%d\n",(int)ceil(ans/2.0));
    return 0;
}
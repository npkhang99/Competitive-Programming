#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int n,a1,b1,c1,a2,b2,c2;

int main(){
    // freopen("INTSLE.inp","r",stdin);
    // freopen("INTSLE.out","w",stdout);
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> a1>> b1>> c1>> a2>> b2>> c2;
        long long d = a1*b2-a2*b1,
            dx = c1*b2-c2*b1,
            dy = a1*c2-a2*c1;
        // printf("%d %d %d\n",d,dx,dy);
        if(d==0 && dx==0 && dy==0){ printf("INFINITE\n"); continue; }
        if(d==0){ printf("NO SOLUTION\n"); continue; }
        if((dx/double(d))-(dx/d)!=0 || (dy/double(d))-(dy/d)!=0){ printf("NO SOLUTION\n"); continue; }
        cout<< dx/d<< " "<< dy/d<< endl;
    }
}

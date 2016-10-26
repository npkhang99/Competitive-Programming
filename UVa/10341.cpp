#include <cstdio>
#include <cmath>
using namespace std;

#define EPS 1E-12

int p, q, r, s, t, u;

double calc(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

bool haveAns(double l, double r){
    return calc(l)*calc(r) <= 0;
}

double bsearch(double l, double r){
    double mid = (l+r)/2.0;
    if(fabs(calc(mid)) <= EPS) return mid;
    if(haveAns(l,mid)) return bsearch(l,mid);
    if(haveAns(mid,r)) return bsearch(mid,r);
    return -1;
}

int main(){
    while(~scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)){
        double x = bsearch(0.0,1.0);
        if(x + 1) printf("%.4lf\n",x);
        else printf("No solution\n");
    }
    return 0;
}

// LightOJ 1043 - Triangle Partitioning
#include <cstdio>
#include <cmath>

const double EPS = 1e-9;

double AB, AC, BC, ratio, H;

bool check(double h){
    double DE = BC * (h/H);
    double ADE = DE * h / 2.0, BCED = (DE+BC) * (H-h) / 2.0;
    return ADE/BCED - ratio > 1e-9;
}

int main(){
    int TC; scanf("%d",&TC);
    for(int T=1; T<=TC; T++){
        scanf("%lf%lf%lf%lf",&AB,&AC,&BC,&ratio);
        H = 1.0 / (1.0/(AB*AB) + 1.0/(AC*AC));
        double l = 0.0, r = H, ans = 0;
        for(int i=0; i<1000; i++){
            // fprintf(stderr, "%lf %lf\n", l, r);
            ans = (l+r)/2.0;
            if(check(ans)) r = ans;
            else l = ans;
        }
        printf("Case %d: %.12lf\n", T, AB * (ans/H));
    }
    return 0;
}

#include <cstdio>
#include <cmath>

const double PI = 4*atan(1);

double a;

int main(){
    while(~scanf("%lf",&a)){
        if(a == 0){
            printf("0.000 0.000 0.000\n");
            continue;
        }
        double ABCD = a*a, S = PI*a*a, _S = 0.25*S - (a*a / 2.0);
        double EF = a*sqrt(2.0 - sqrt(3.0)), alpha = 2.0*asin((EF / 2.0) / a);
        double S1 = (alpha / (2.0*PI)) * S - 0.5 * EF * (a * cos(alpha / 2.0));

        double ans1 = EF*EF + 4.0*S1, ans2 = 4.0*_S - 2.0*ans1, ans3 = ABCD - (ans1 + ans2);
        printf("%.3lf %.3lf %.3lf\n", ans1, ans2, ans3);
    }
    return 0;
}

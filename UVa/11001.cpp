#include <cstdio>
#include <cmath>
using namespace std;

double V_total, V0, D;

int main(){
    while(scanf("%lf %lf",&V_total,&V0), V_total || V0){
        D = 0;
        int ans = 0, flag = 0;
        for(int i=1; i <= 6e4 && V_total / i >= V0; i++){
            if(i * 0.3 * sqrt(V_total / i - V0) - D > 1e-9)
                ans = i, D = i * 0.3 * sqrt(V_total / i - V0), flag = 1;
            else if(fabs(D - i * 0.3 * sqrt(V_total / i - V0)) < 1e-9) flag = 0;
        }
        printf("%d\n",ans * flag);
    }
    return 0;
}

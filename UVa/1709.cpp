#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int p, a, b, c, d, n;

double f(int k){
    return p * (sin(a*k + b) + cos(c*k + d) + 2);
}

int main(){
    while(~scanf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n)){
        double ans = 0.0, hi = f(1);
        for(int i=2; i<=n; i++){
            double curr = f(i);
            if(curr > hi){
                hi = curr;
                continue;
            }
            ans = max(ans, hi - curr);
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}

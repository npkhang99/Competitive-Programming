#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int d[] = {5,10,20,50,100,200};

int m, a[9];
long long dp[20009];

int main(){
    while(scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]), a[0] || a[1] || a[2] || a[3] || a[4] || a[5]){
        double x; scanf("%lf",&x);
        m = x*100;
        for(int i=0; i <= 200*m; i++)
            dp[i] = 10E17;
        dp[0] = 0;
        for(int i=0; i<)
    }
    return 0;
}

// ACM ICPC 2017 World Finals
// Problem E - Need for Speed
#include <bits/stdc++.h>
using namespace std;

const int N = 1009;
const double eps = 1e-9;

int n, t, d[N]={}, s[N]={};

bool check(double c){
    double real_total = 0.0;
    for(int i=0; i<n; i++){
        if(s[i] + c < 0) return false;
        real_total += (double)d[i] / (s[i] + c);
    }
    return real_total - t < eps;
}

int main(){
    while(~scanf("%d %d", &n, &t)){
        for(int i=0; i<n; i++){
            scanf("%d %d", &d[i], &s[i]);
        }

        double c = 0.0, l = -1e9, r = 1e9;
        for(int steps=0; steps < 100; steps++){
            c = (l + r) / 2.0;
            if(check(c)) r = c;
            else l = c;
        }

        printf("%.9lf\n", c);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 10009;
const double pi = 4*atan(1);

int n;
double a[N]={};

double angle(double r){
    double x = 0;
    for(int i=0; i<n; i++){
        x += acos((pow(a[i]+r,2) + pow(a[i+1]+r,2) - pow(a[i]+a[i+1],2)) / (2.0*(a[i]+r)*(a[i+1]+r)));
    }
    return x;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lf",&a[i]);
    a[n] = a[0];

    double l = 0.0, r = 10E8, ans;
    while(l <= r){
        double mid = (l+r)/2.0;
        if(angle(mid) <= 2*pi){
            ans = mid;
            if(abs(angle(mid) - 2*pi) <= 1e-6) break;
            r = mid;
        }else l = mid;
    }
    printf("%.3lf\n",ans);
    return 0;
}

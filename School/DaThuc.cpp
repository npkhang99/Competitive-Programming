#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 20;

int n;
double a[N]={};

int check(double x){
    double fin = 0;
    for(int i=0; i<=n; i++) fin += a[i]*pow(x,i);
    return fin<0? -1:1;
}

bool isAns(double x){
    double fin = 0;
    for(int i=0; i<=n; i++) fin += a[i]*pow(x,i);
    // printf("%lf %lf\n",x,fin);
    return abs(fin) <= 0.00000000001;
}

void bsearch(double l, double r){
    // printf("%.6lf %.6lf\n",l,r);
    if(l>r) return;
    double mid = (l+r) / 2.0;
    if(isAns(mid)){
        printf("%d\n",int(mid*1000));
        exit(0);
    }
    int seg1 = check(l)*check(mid), seg2 = check(mid)*check(r);
    // printf("%d %d\n",seg1,seg2);
    if(seg1 < 0) bsearch(l,mid);
    if(seg2 < 0) bsearch(mid,r);
}

int main(){
    // freopen("DaThuc.inp","r",stdin);
    // freopen("DaThuc.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<=n; i++) scanf("%lf",&a[i]);
    if(a[0] == 0){
        printf("0\n");
        return 0;
    }
    bsearch(-1000000,0);
    bsearch(0,1000000);
    return 0;
}

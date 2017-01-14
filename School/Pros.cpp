#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define long long long

bool flag = false;
long a=0, b = 1, ans[10]={};
double p;

void reset(){
    a = 0, b = 1, flag = false;
    for(int i=0; i<10; i++) ans[i] = 0;
}

long GCD(long a, long b){
    long r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void createAns(int now, long sum, long left){
    // printf("%d %lld %lld\n",now,sum,left);
    if(!sum && !left){
        flag = true;
        return;
    }
    if(!now || now * left < sum) return;
    long n = min(left, sum/now);
    for(long i=n; i>=0; i--){
        if(flag) return;
        ans[now] = i;
        createAns(now-1,sum-now*i,left-i);
    }
}

int main(){
    // freopen("Pros.inp","r",stdin);
    // freopen("Pros.out","w",stdout);
    while(scanf("%lf",&p)!=EOF){
        reset();
        while(a != p*b){
            b *= 10;
            a = p*b;
        }
        long r = GCD(a,b);
        a /= r; b /= r;
        // printf("%lld %lld\n",a,b);
        createAns(5,a,b);
        for(int i=1; i<=5; i++) printf("%lld ",ans[i]);
        printf("\n");
    }
    return 0;
}

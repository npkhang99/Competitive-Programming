#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=509;

int n, x, y;
long long a[N][N], r[N]={}, c[N]={};

int legit(int i, long long need){
    return r[i] + (i==x? need:0) == r[x]+need && c[i] + (i==y? need:0) == c[y]+need;
}

long long check(long long need){
    if(need<=0) return -1;
    for(int i=0; i<n; i++)
        if(!legit(i,need)) return -1;
    for(int i=0; i<n; i++)
        if(!legit(i,need)) return -1;
    long long mainSum=0, secondSum=0;
    for(int i=0; i<n; i++)
        mainSum += a[i][i]==0? need:a[i][i],
        secondSum += a[i][n-i-1]==0? need:a[i][n-i-1];
    if(mainSum!=secondSum || mainSum!=r[x]+need || secondSum!=r[x]+need) return -1;
    return need;
}

long long find(){
    long long need = 0;
    if(x==0) need = r[1]-r[0];
    else need = r[0] - r[x];
    return check(need);
}

int main(){
    scanf("%d\n",&n);
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
            if(!a[i][j]) x=i, y=j;
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    if(x==y || y==n-x-1){
        long long mainSum=0, secondSum=0;
        for(int i=0; i<n; i++)
            mainSum += a[i][i],
            secondSum += a[i][n-i-1];
        if(x==y && y==n-x-1){
            if(mainSum == secondSum){
                printf("%lld\n",find());
                return 0;
            }
            printf("-1\n");
            return 0;
        }
        if(x==y){
            printf("%lld\n",check(secondSum-mainSum));
            return 0;
        }
        if(y==n-x-1){
            printf("%lld\n",check(-secondSum+mainSum));
            return 0;
        }
    }
    // printf("1\n");
    printf("%lld\n",find());
    return 0;
}

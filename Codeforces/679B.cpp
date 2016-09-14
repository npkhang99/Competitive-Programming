#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define cbrt(x) pow(x,1.0/3.0)
#define min(a,b) (a<b)?a:b

long long n;

long long cube(int x){
    return x*x*x;
}

int main(){
    cin>> n;
    int i=floor(cbrt(n)), cnt=0;
    long long ans=0;
    while(i>0){
        if(i==1){
            cnt+=min(7,n-ans);
            ans+=min(7,n-ans);
            printf("%d %d %I64d %I64d\n",cnt,i,ans,n-ans);
            break;
        }
        cnt+=1;
        ans+=cube(i);
        printf("%d %d %I64d %I64d\n",cnt,i,ans,n-ans);
        while((i>0 && cube(i)>n-ans) || cube(i-1)>n-ans) i-=1;
        if(i==2 && n-ans-cube(2)<6) i=1;
    }
    printf("%d %I64d",cnt,ans);
    return 0;
}
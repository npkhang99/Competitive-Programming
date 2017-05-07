#include <iostream>
#include <stdio.h>
using namespace std;

#define max(a,b) (a>b)?a:b

int n,m,t;

void swap(int &a, int &b){ a+=b; b=a-b; a=a-b; }

int main(){
    scanf("%d",&t);
    for(int i=0; i<t; i++){
        scanf("%d%d",&n,&m);
        long long ans=max(n*m/2,n*m-n*m/2);
        if(n==1 || m==1) ans=n*m;
        if(n==2 || m==2){
            if(n!=2) swap(n,m);
            double t=m/4.0;
            ans = 2*(m/4);
            if(t-m/4==0.25) ans+=1;
            else if(t-m/4>0.25) ans+=2;
            ans*=2;
        }
        printf("Case %d: %lld\n",i+1,ans);
    }
    return 0;
}

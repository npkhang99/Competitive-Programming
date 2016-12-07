// CodeChef
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, a[N], T;
long long p, q;

void doc(){
    scanf("%d %lld %lld",&n,&p,&q);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
}

void xuly(){
    int ans = 0;
    long long curr = p + 2*q;
    sort(a,a+n);
    for(int i=0; i<n; i++)
        if(curr >= a[i]){
            // printf("%d %lld\n",i,curr);
            if(a[i]%2 && !p) continue;
            ans+=1;
            int qNeed = a[i]/2;
            a[i]-=2*min(q,(long long)qNeed);
            q-=min(q,(long long)qNeed);
            p-=a[i];
            curr = p+2*q;
        }
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        doc();
        xuly();
    }
    return 0;
}

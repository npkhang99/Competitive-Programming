#include <iostream>
#include <stdio.h>
using namespace std;

const int N=109;

int n, k, T, a[N]={}, cnt[N]={}, b[N]={};

int main(){
    scanf("%d",&T);
    for(int tcase=0; tcase<T; tcase++){
        scanf("%d%d",&n,&k);
        int ans=0;
        for(int i=0; i<n; i++){
            b[i] = cnt[i] = 0;
            scanf("%d",&a[i]);
            a[i]-=1;
        }
        for(int i=0; i<n; i++){
            if(b[a[i]]) continue;
            if(a[i]==i){ b[a[i]] = 1; continue; }
            cnt[a[i]]+=1;
        }
        for(int i=0; i<n; i++)
            if(!b[i] && cnt[i]>=k) ans+=1;
        printf("%d\n",ans);
    }
    return 0;
}
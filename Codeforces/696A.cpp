#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, type;
long long u, v, w;
unordered_map<long long,long long> a;

void updateLCA(long long u, long long v, long long w){
    while(u!=v){
        if(u>v) swap(u,v);
        a[v]+=w;
        v >>= 1;
    }
}

long long LCA(long long u, long long v){
    long long ans=0;
    while(u!=v){
        if(u>v) swap(u,v);
        ans+=a[v];
        v >>= 1;
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n ;i++){
        scanf("%d",&type);
        if(type==1){
            scanf("%lld%lld%lld",&u,&v,&w);
            updateLCA(u,v,w);
            continue;
        }
        scanf("%lld%lld",&u,&v);
        printf("%lld\n",LCA(u,v));
    }
    return 0;
}

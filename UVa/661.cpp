#include <iostream>
#include <stdio.h>
using namespace std;

int max(int a,int b){ return (a>b)?a:b; }

const int N=29;

int n, m, c, a[N]={}, b[N]={}, T=0;

int main(){
    while(cin>> n>> m>> c){
        if(n==0 && m==0 && c==0) break;
        int maxConsumption=0, currConsumption=0;
        for(int i=0; i<n; i++){ cin>> a[i]; b[i]=0; }
        for(int i=0; i<m; i++){
            int x; cin>> x;
            if(!b[x-1]){ b[x-1]=!b[x-1]; currConsumption+=a[x-1]; }
            else{ b[x-1]=!b[x-1]; currConsumption-=a[x-1]; }
            maxConsumption=max(maxConsumption,currConsumption);
        }
        if(maxConsumption>c) printf("Sequence %d\nFuse was blown.\n\n",++T);
        else printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",++T,maxConsumption);
    }
    return 0;
}

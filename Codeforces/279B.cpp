#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, t, a[N]={};

int main(){
    cin>> n>> t;
    for(int i=1; i<=n; i++){
        cin>> a[i];
        a[i] += a[i-1];
    }
    int ans=0, i=1, j=0;
    while(i<=n && j<=n){
        while(a[j]-a[i-1]>t) i+=1;
        ans = max(ans, j-i+1);
        j+=1;
    }
    printf("%d\n",ans);
    return 0;
}
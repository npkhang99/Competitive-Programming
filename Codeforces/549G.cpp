#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=200009;

int n, a[N]={};

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]), a[i]-=n-i;
    sort(a,a+n);
    for(int i=0; i<n; i++){
        a[i]+=n-i;
        if(i>0 && a[i]<a[i-1]){
            printf(":(\n");
            return 0;
        }
    }
    for(int i=0; i<n; i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 5009;

int n, a[N]={}, b[N]={}, diff[N]={};

int main(){
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        printf("? %d %d\n",1,i+1); fflush(stdout);
        scanf("%d",&b[i]);
    }
    for(int i=1; i<n-1; i++) diff[i] = b[i+1] - b[i];
    printf("? 2 3\n"); fflush(stdout); scanf("%d",&b[0]);
    diff[0] = b[0] - b[2];
    a[0] = ((b[2] - b[0]) + b[1])/2;
    for(int i=1; i<n; i++) a[i] = a[i-1]+diff[i-1];
    printf("!");
    for(int i=0; i<n; i++) printf(" %d",a[i]);
    printf("\n");
    return 0;
}

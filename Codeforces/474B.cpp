#include <iostream>
#include <stdio.h>
using namespace std;

const int N=1000009;

int n, a[N]={}, k=0;

int main(){
    cin>> n;
    for(int i=0; i<n; i++){
        int x;
        cin>> x;
        for(int j=k; j<k+x; j++) a[j]=i;
        k+=x;
    }
    cin>> n;
    for(int i=0; i<n; i++){
        int x;
        cin>> x;
        printf("%d\n",a[x-1]+1);
    }
    return 0;
}

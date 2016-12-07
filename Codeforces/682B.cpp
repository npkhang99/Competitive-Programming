#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, a[N];

int main(){
    cin>> n;
    if(n==1){
        cout<< 2;
        exit(0);
    }
    for(int i=0; i<n; i++) cin>> a[i];
    
    sort(a,a+n);
    int k=1;
    a[0]=k++;
    for(int i=1; i<n; i++)
        if(a[i]!=k && a[i-1]!=a[i] && a[i]-a[i-1]>1) a[i]=k++;
        else if(a[i]==k) k+=1;
    cout<< a[n-1]+1;
    return 0;
}

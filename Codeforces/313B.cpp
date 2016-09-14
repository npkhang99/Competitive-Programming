#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int N=100009;

int n, a[N]={};
string st;

int main(){
    cin>> st;
    if(st[0]==st[1]) a[1]=1;
    for(int i=2; i<st.size()+1; i++)
        if(st[i-2]==st[i-1]) a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    cin>> n;
    for(int i=0; i<n; i++){
        int x,y; cin>> x>> y;
        printf("%d\n",a[y]-a[x]);
    }
    return 0;
}
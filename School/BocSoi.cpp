#include <iostream>
#include <stdio.h>
using namespace std;

//---------------------------------------------------------
int main(){
    int n, m;
    freopen("BocSoi.inp","r",stdin);
    freopen("BocSoi.out","w",stdout);
    cin>> n>> m;
    cout<< n%(m+1);
}

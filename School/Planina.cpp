#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int n;
//---------------------------------------------------------
int main(){
    freopen("Planina.inp","r",stdin);
    freopen("Planina.out","w",stdout);
    cin>> n;
    long long kq=pow(2,n)-1;
    (cout<< fixed).precision(0);
    cout<< pow(kq,2);
    return 0;
}
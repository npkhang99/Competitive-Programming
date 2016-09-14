#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int a[1000], s1, s2, s3, vt;
//---------------------------------------------------------
void xuly(){
    memset(a,0,sizeof(a));
    vt=0;
    for (int i=1; i<=s1; i++)
        for (int j=1; j<=s2; j++)
            for (int k=1; k<=s3; k++){
                a[i+j+k]++;
                if (a[i+j+k]>a[vt] || (a[i+j+k]==a[vt] && i+j+k<vt)) vt=i+j+k;
            }
}
//---------------------------------------------------------
int main(){
    freopen("XucXac.inp", "r", stdin);
    freopen("XucXac.out", "w", stdout);
    cin>> s1>> s2>> s3;
    xuly();
    cout<< vt;
}
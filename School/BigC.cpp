#include <iostream>
#include <algorithm>
#include <fstream>
#include <memory.h>
#define fi "BigC.inp"
#define fo "BigC.out"
#define for1(i,a,b) for(long i=a; i<=b; i++)
#define for2(i,a,b) for(long i=a; i>=b; i--)
using namespace std;

long n, k, a[1000];
//---------------------------------------------------------
void docfile(){
    fstream f;
    f.open(fi, ios::in);
    f>> n>> k;
    for1(i,0,n-1) f>> a[i];
    f.close();
}
//---------------------------------------------------------
void xuat(long x){
    fstream f;
    f.open(fo, ios::out);
    f<< x; cout<< x;
    f.close();
}
//---------------------------------------------------------
void xuly(){
    long d, w;
    bool b[1000];
    memset(b, 0, sizeof(b));
    sort(a, a+n);
    d=0;
    for2(i,n-1,0){
        if(!b[i]){
            w=a[i]; b[i]=true;
            for2(j,i-1,0){
                if((w+a[j]<=k) && (!b[j])){
                    w+=a[j];
                    b[j]=true;
                }
            d++;
            }
        }
    }
    xuat(d);
}
//---------------------------------------------------------
int main(){
    docfile;
    for1(i,0,n) cout<< a[i]<< " ";
    xuly;
    return 0;
}

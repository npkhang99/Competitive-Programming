#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;

char a[1000];
//---------------------------------------------------------
void docfile(){
    fstream f;
    f.open("DoiXung.inp", ios::in);
    f.getline(a,1000);
    f.close();
}
//---------------------------------------------------------
void xuat(int x){
    fstream f;
    f.open("DoiXung.out", ios::out);
    f<< x;
    f.close();
}
//---------------------------------------------------------
void xuly(){
    int n, L[1000][1000];
    n=strlen(a);
    for (int i=1; i<=n; i++){
        L[0][i]=0;
        L[i][0]=0;
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (a[i-1]=a[n-j]){
                L[i][j]=L[i-1][j-1]+1;
            }else L[i][j]=fmax(L[i-1][j], L[i][j-1]);
    cout<< L[n][n];
}
//---------------------------------------------------------
int main(){
    docfile();
    xuly();
    return 0;
}

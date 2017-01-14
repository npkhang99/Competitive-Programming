#include <iostream>
#include <math.h>
using namespace std;

int a[101], b[101], n, m;
bool c[101];
//---------------------------------------------------------
void doc(){
    int x;
    for (int i=0; i<=100; i++){
        a[i]=0; b[i]=0;
    }
    cin>> n;
    for (int i=1; i<=n; i++){
        cin>> x;
        a[x]++;
    }
    cin>> m;
    for (int i=1; i<=m; i++){
        cin>> x;
        b[x]++;
    }
}
//---------------------------------------------------------
bool canPair(int x){
    return ((b[x-1]>0)||(b[x]>0)||(b[x+1]>0));
}
//---------------------------------------------------------
void xuly(){
    int d=0;
    for (int i=1; i<=100; i++){
        while ((a[i]>0)&&(canPair(i))){
            if (b[i-1]>0){
                b[i-1]--; a[i]--; d++;
            }else{
                if (b[i]>0){
                    b[i]--; a[i]--; d++;
                }else{
                    if (b[i+1]>0){
                        b[i+1]--; a[i]--; d++;
                    }
                }
            }
        }
    }
    cout<< d;
}
//---------------------------------------------------------
int main(){
    doc();
    xuly();
    return(0);
}

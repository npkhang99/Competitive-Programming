#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;

const int N=31250009;
int n, m;
bitset<32> a[N];
//---------------------------------------------------------
void xuly(){
    int i=0, d=0;
    while (d<m){
        if(!a[i >> 5].test(i & 31)){
            cout<< i<< " "; d++;
        }
        i++;
    }
}
//---------------------------------------------------------
int main(){
    freopen("Index.inp", "r", stdin);
    freopen("Index.out", "w", stdout);
    cin>> n>> m;
    for(int i=1; i<=n; i++){
        int val;
        cin>> val;
        a[val >> 5].set(val & 31);
    }
    xuly();
    return 0;
}

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N=100009;
int n, m;
long long a[N], L[N];
//---------------------------------------------------------
void getData(){
    int x;
    memset(a, 0, sizeof(a));
    m=0;
    cin>> n;
    for(int i=1; i<=n; i++){
        cin>> x; m=max(m, x);
        a[x]=a[x]+x; L[x]=a[x];
    }
}
//---------------------------------------------------------
void Solve(){
    for(int i=0; i<=m; i++){
        L[i]=max(L[i-1], L[i]+L[i-2]);
    }
    cout<< L[m];
}
//---------------------------------------------------------
int main(){
    getData();
    Solve();
    return 0;
}

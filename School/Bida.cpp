#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int a[200000], n, m;
stack<int> st;
//---------------------------------------------------------
void nap(int x){
    for(int i=m+1; i<=x; i++)
        st.push(i);
}
//---------------------------------------------------------
void xuly(){
    m=0;
    for (int i=1; i<=n; i++){
        if (a[i]>m){
            nap(a[i]); m=a[i];
        }
        int u=st.top(); st.pop();
        if (a[i]==u) continue;
        if (a[i]!=u){
            cout<< "YES";
            return;
        }
    }
    cout<< "NO";
}
//---------------------------------------------------------
int main(){
    freopen("Bida.inp", "r", stdin);
    freopen("Bida.out", "w", stdout);
    cin>> n; for(int i=1; i<=n; i++) cin>> a[i];
    xuly();
}

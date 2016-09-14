#include <iostream>
using namespace std;

const int N=509;

int a[N][N]={}, n, k;

void xuly(){
    int _n=n*n, ans=0;
    for(int i=1; i<=n; i++){
        for(int j=n; j>=k; j--) a[i][j]=_n--;
        ans+=a[i][k];
    }
    cout<< ans<< endl;
    _n=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            if(a[i][j]==0) cout<< _n++<< " ";
            else cout<< a[i][j]<< " ";
        cout<< endl;
    }
}

int main(){
    cin>> n>> k;
    xuly();
    return 0;
}

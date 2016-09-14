#include <iostream>
using namespace std;

const int N=100009;

int n;

int xuly(){
    int a[N]={}, l=1;
    a[1]=1;
    for(int i=2; i<=n; i++){
        a[++l]=1;
        while(a[l]==a[l-1]) a[--l]++;
    }
    for(int i=1; i<=l; i++) cout<< a[i]<< " ";
}

int main(){
    cin>> n;
    xuly();
    return 0;
}

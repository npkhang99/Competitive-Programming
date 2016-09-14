#include <iostream>
#include <algorithm>
using namespace std;

const int N=109;
int a[N], n, m;
//---------------------------------------------------------
void doc(){
    cin>> n>> m;
    for(int i=0; i<n; i++) cin>> a[i];
}
//---------------------------------------------------------
int comp(int a, int b){
    return a>b;
}
//---------------------------------------------------------
void greedy(){
    sort(a,a+n,comp);
    int count=0;
    for(int i=0; i<n; i++)
        if(m){
            count++;
            m=max(0, m-a[i]);
        }
    cout<< count;
}
//---------------------------------------------------------
int main(){
    doc();
    greedy();
    return 0;
}

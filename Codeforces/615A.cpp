#include <iostream>
#include <vector>
using namespace std;

const int N=109;
int n, m;
vector<int> a[N];
//---------------------------------------------------------
void doc(){
    cin>> n>> m;
    for(int i=1; i<=n; i++){
        int x;
        cin>> x;
        for(int j=0; j<x; j++){
            int y;
            cin>> y;
            a[i].push_back(y);
        }
    }
}
//---------------------------------------------------------
void xuly(){
    int b[N];
    for(int i=1; i<=m; i++) b[i]=false;
    for(int i=1; i<=n; i++)
        for(int j=0; j<a[i].size(); j++)
            b[a[i][j]]=true;
    for(int i=1; i<=m; i++)
        if(!b[i]){
            cout<< "NO"; return;
        }
    cout<< "YES";
}
//---------------------------------------------------------
int main(){
    doc();
    xuly();
    return 0;
}

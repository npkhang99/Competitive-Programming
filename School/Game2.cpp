#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory.h>
#define forit(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
using namespace std;

const int N=209;
vector< vector<int> > a(N), g(N);
int n, k, status[N];
bool b[N];
//---------------------------------------------------------
void doc(){
    int m;
    cin>> n>> m>> k;
    for(int i=1; i<=m; i++){
        int u,v;
        cin>> u>> v;
        a[u].push_back(v);
        g[v].push_back(u);
    }
}
//---------------------------------------------------------
bool isLoss(int i){
    if(a[i].size()==0) return true;
    forit(it,a[i])
        if(status[*it]!=1) return false;
    return true;
}
//---------------------------------------------------------
bool isWin(int i){
    forit(it,g[i])
        if(status[*it]==2) return true;
    return false;
}
//---------------------------------------------------------
void gan(int i){
    int curr_stat;
    curr_stat=0;
    if(isLoss(i)) curr_stat=2;
    else if(isWin(i)) curr_stat=1;
    status[i]=curr_stat;
    if(curr_stat!=0)
        forit(it,g[i])
            if(status[*it]==0) gan(*it);
}
//---------------------------------------------------------
void xuly(){
    memset(status,0,sizeof(status));
    for(int i=1; i<=n; i++)
        if(a[i].size()==0) gan(i);
    for(int i=1; i<=n; i++)
        cout<< status[i]<< " ";
    cout<<endl<< status[k];
}
//---------------------------------------------------------
int main(){
    freopen("Game2.inp","r",stdin);
    //freopen("Game2.out","w",stdout);
    doc();
    xuly();
    return 0;
}
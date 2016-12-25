#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#define forit(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
using namespace std;

const int N=1009;
vector< vector<int> > g(N), a(N);
int n, m, c[N][N], dem, chutrinh, tr[N];
bool b[N];
//---------------------------------------------------------
void doc(){
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin>> u>> v;
        g[u].push_back(v);
    }
}
//---------------------------------------------------------
void found(int p, int i){
    chutrinh++;
    do{
        c[p][i]++;
        i=p;
        p=tr[i];
    }while (p!=0);
}
//---------------------------------------------------------
void DFS(int i, int goc){
    b[i]=true;
    forit(it,g[i])
        if(!b[*it]){
            tr[*it]=i;
            DFS(*it,goc);
        }
        else if(b[*it] && *it==goc) found(i, goc);
    b[i]=false;
}
//---------------------------------------------------------
void xuly(){
    dem=0;
    for(int i=1; i<=n; i++){
        memset(b,0,sizeof(b));
        memset(tr,0,sizeof(tr));
        DFS(i,i);
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(c[i][j]==chutrinh){
                dem++;
                a[i].push_back(j);
            }
    if(dem==0 || chutrinh==0){
        cout<< "-1\n";
        return;
    }
    cout<< dem<< '\n';
    for(int i=1; i<=n; i++)
        for(int j=0; j<a[i].size(); j++)
            cout<< i<< " "<< a[i][j]<< (j == a[i].size()-1? '\n':' ');
}
//---------------------------------------------------------
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    doc();
    xuly();
}

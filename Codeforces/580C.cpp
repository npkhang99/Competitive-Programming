#include <iostream>
#include <vector>
#include <algorithm>
#define forit(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
using namespace std;

const int N=100009;
vector< vector<int> > a(N);
int n, m, d[N], dem, child[N];
bool b[N], cat[N];
//---------------------------------------------------------
void doc(){
    cin>> n>> m;
    for(int i=1; i<=n; i++){
        int x; cin>> x;
        if(x==0) cat[i]=false;
        else cat[i]=true;
    }
    for(int i=1; i<n; i++){
        int x, y;
        cin>> x>> y;
        a[x].push_back(y); a[y].push_back(x);
    }
}
//---------------------------------------------------------
void DFS(int i){
    if(d[i]>m) return;
    b[i]=true;
    forit(it,a[i])
        if(!b[*it]){
            if(!cat[*it] && (d[i]==N || d[i]<=m))d[*it]=0;
            if(cat[*it])d[*it]=d[i]+1;
            child[i]++;
            DFS(*it);
        }
}
//---------------------------------------------------------
bool isLeaf(int i){
    return child[i]==0;
}
//---------------------------------------------------------
void xuly(){
    for(int i=1; i<=n; i++){d[i]=N; b[i]=false;}
    d[1]=cat[1]; dem=0;
    DFS(1);
    for(int i=1; i<=n; i++)
        if(isLeaf(i) && d[i]<=m) dem++;
    cout<< dem;
}
//---------------------------------------------------------
int main(){
    doc();
    xuly();
    return 0;
}
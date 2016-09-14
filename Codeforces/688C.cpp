#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int N=100009;

int n, m, b[N]={}, conti=1;
vector<int> a[N], ans1, ans2;

void doc(){
    cin>> n>> m;
    for(int i=0; i<m; i++){
        int x,y; cin>> x>> y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }
}

void DFS(int u, int k){
    b[u]=k;
    if(k==1) ans1.push_back(u);
    if(k==2) ans2.push_back(u);
    for(int i=0; i<a[u].size(); i++){
        if(!conti) return;
        int v=a[u][i];
        if(b[v]==k){ conti=0; return; }
        if(!b[v]) DFS(v,3-k);
    }
}

void xuly(){
    for(int i=0; i<n; i++)
        if(!b[i]){
            DFS(i,1);
            if(!conti) break;
        }
    if(!conti){ cout<< -1; return; }
    printf("%d\n",ans1.size());
    for(int i=0; i<ans1.size(); i++) printf("%d ",ans1[i]+1);
    printf("\n%d\n",ans2.size());
    for(int i=0; i<ans2.size(); i++) printf("%d ",ans2[i]+1);
}

int main(){
    doc();
    xuly();
    return 0;
}
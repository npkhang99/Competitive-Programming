// Tarjan's algorithm in finding Strongly Connected Component
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
 
const int N=10009;
 
int n, m, low[N]={}, num[N]={}, b[N]={}, cnt=0, ans=0;
vector<int> a[N];
stack<int> s;
 
void doc(){
    cin>> n>> m;
    for(int i=0; i<m; i++){
        int x,y; cin>> x>> y;
        a[x].push_back(y);
    }
}
 
void DFS(int u){
    num[u]=++cnt;
    low[u]=cnt;
    s.push(u);
    for(int i=0; i<a[u].size(); i++){
        int v=a[u][i];
        if(b[v]) continue;
        if(!num[v]){
            DFS(v);
            low[u]=min(low[u],low[v]);
        }else low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u]){
        ans+=1;
        do{
            int x=s.top(); s.pop();
            b[x]=1;
        }while(x!=u);
    }
}
 
void xuly(){
    for(int i=1; i<=n; i++)
        if(!num[i]) DFS(i);
    cout<< ans;
}
 
int main(){
    doc();
    xuly();
    return 0;
}

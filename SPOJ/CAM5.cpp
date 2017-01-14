// SPOJ submission 17395999 (C++ 5) plaintext list. Status: AC, problem CAM5, contest SPOJ. By mansblacks (Khang), 2016-07-30 06:32:44.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int N=100009;

int T, n, e, b[N]={};
vector<int> a[N];

void xuly(){
    int ans=0;
    cin>> n>> e;
    for(int i=0; i<n; i++) b[i]=0;
    for(int i=0; i<n; i++) a[i].clear();
    for(int i=0; i<e; i++){
        int x,y; cin>> x>> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue<int> q;
    for(int i=0; i<n; i++)
        if(!b[i]){
            ans+=1;
            q.push(i);
            while(!q.empty()){
                int u=q.front(); q.pop();
                b[u]=1;
                for(int j=0; j<a[u].size(); j++){
                    int v=a[u][j];
                    if(!b[v]) q.push(v);
                }
            }
        }
    printf("%d\n",ans);
}

int main(){
    cin>> T;
    for(int _=0; _<T; _++) xuly();
    return 0;
}

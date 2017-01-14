#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int N=5009;

int n, m, low[N]={}, num[N]={}, b[N]={}, c[N]={}, d[N]={}, cnt=0, ans=0;
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
        while(s.top()!=u){
            // printf("%d ",s.top());
            b[s.top()]=1;
            c[s.top()]=ans;
            s.pop();
        }
        // printf("%d\n",s.top());
        b[s.top()]=1; c[s.top()]=ans;
        s.pop();
    }
}

void xuly(){
    for(int i=1; i<=n; i++)
        if(!num[i]) DFS(i);
    // printf("-------------------------\n");
    // for(int i=1; i<=n; i++) printf("%d ",num[i]);
    // printf("\n");
    // for(int i=1; i<=n; i++) printf("%d ",low[i]);
    for(int i=1; i<=n; i++)
        for(int j=0; j<a[i].size(); j++)
            if(c[a[i][j]]!=c[i]) d[c[a[i][j]]]=1;
    int x=0;
    for(int i=1; i<=ans; i++) x+=d[i];
    cout<< ans-x;
}

int main(){
    freopen("Message.inp","r",stdin);
    freopen("Message.out","w",stdout);
    doc();
    xuly();
    return 0;
}

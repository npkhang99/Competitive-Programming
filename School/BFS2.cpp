#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 100009;

int n, f, d[N] = {}, tr[N] = {};
vector<int> a[N], path;

void BFS(int s, int last){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        d[i] = 10E8;
        tr[i] = 0;
    }

    d[s] = 1; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i<a[u].size(); i++){
            int v = a[u][i];
            if(d[u] + 1 < d[v]){
                q.push(v);
                d[v] = d[u] + 1;
                tr[v] = u;
                if(d[f] < d[v]) f = v;
            }
        }
    }
    
    if(f == last){
        printf("%d\n", d[last]);
        f = last;
    } else BFS(f, s);
}

void getPath(int s){
    if(tr[s]){
        getPath(tr[s]);
        path.push_back(s);
    }
}

int main(){
    // freopen("BFS2.inp","r",stdin);
    // freopen("BFS2.out","w",stdout);
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int x, y; scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    BFS(1,0);
    getPath(f);

    int len=10E8;
    vector<int> ans;

    sort(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++){
        int u = path[i];
        if(len > max(d[u] - 1, d[f] - d[u])){
            ans.clear();
            ans.push_back(u);
            len = max(d[u] - 1, d[f] - d[u]);
        } else if(len == max(d[u] - 1, d[f] - d[u])){
            ans.push_back(u);
        }
    }

    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}

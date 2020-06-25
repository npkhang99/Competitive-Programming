#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a = 1, b = 1, mark[N]={};
bool pass[N]={};
vector<int> adj[N], S;

bool find_route(int u){
    S.push_back(u);
    pass[u] = true;

    if(u == n) return true;

    bool found = false;
    for(int v : adj[u])
        if(!pass[v] && !found) found = find_route(v);

    if(!found) S.pop_back();
    return found;
}

void dfs(int u, int color){
    mark[u] = color; pass[u] = true;
    for(int v : adj[u])
        if(!pass[v] && (!mark[v] || mark[v] == color)){
            if(color == 1 && !mark[v]) a++;
            if(color == 2 && !mark[v]) b++;
            dfs(v,color);
        }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int x, y; scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(pass, 0, sizeof pass);
    find_route(1);

    if(S.size() % 2 != 0){
        a = S.size() / 2 + 1;
        b = S.size() / 2;
    }else a = b = S.size() / 2;

    for(int i = 0; i < S.size(); i++)
        if(i < a) mark[S[i]] = 1;
        else mark[S[i]] = 2;

    memset(pass, 0, sizeof pass);
    dfs(1,1);
    dfs(n,2);

    printf("%s\n", a > b? "Fennec":"Snuke");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int N = 159;

int n, m, s, t, c[N][N]={}, f;
vector<int> a[N], p;

void augment(int v, int minEdge){
    if(v == s){
        f = minEdge;
        return;
    }
    if(p[v] != -1){
        augment(p[v], min(minEdge, c[p[v]][v]));
        c[p[v]][v] -= f; c[v][p[v]] += f;
    }
}

int pathLength(int i){
    if(i == t) return 0;
    return pathLength(p[i]) + 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y, w; scanf("%d%d%d",&x,&y,&w);
        a[x].push_back(y);
        a[y].push_back(x);
        c[x][y] = c[y][x] = w;
    }

    s = 0; t = n+1;

    for(int i=1; i<=n; i++){
        a[s].push_back(i);
        a[i].push_back(t);
        c[s][i] = c[i][t] = 1e9;
    }

    long long mf = 0;
    while(true){
        f = 0;
        bitset<N> vis; vis[s] = true;
        queue<int> q; q.push(s);
        p.assign(N,-1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t && pathLength(t) > 2) break;
            else if(u == t) continue;
            for(int i = 0; i < a[u].size(); i++){
                int v = a[u][i];
                if(c[u][v] > 0 && !vis[v])
                    vis[v] = true, q.push(v), p[v] = u;
            }
        }
        augment(t, 1e9);
        if(f == 0) break;
        mf += f;
    }

  printf("%lld\n", mf);
  return 0;
}

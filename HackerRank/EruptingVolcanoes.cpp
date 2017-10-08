// University CodeSprint 3 - Erupting Volcanoes
#include <bits/stdc++.h>
using namespace std;

#define iii(x,y,z) iii(ii(x,y),z)

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N = 309;
const int dx[] = {-1,-1,0,1,1,1,0,-1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};

int n, m, a[N][N]={};

bool can_go(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < n;
}

void bfs(int x, int y, int w){
    queue<iii> q;
    bool b[N][N]={};
    q.push(iii(x,y,w));
    b[x][y] = true;
    while(!q.empty()){
        int x = q.front().first.first,
            y = q.front().first.second;
        w = q.front().second;
        a[x][y] += w; q.pop();
        if(--w == 0) continue;
        for(int i = 0; i < 8; i++){
            int u = x + dx[i],
                v = y + dy[i];
            if(can_go(u,v) && !b[u][v]){
                q.push(iii(u,v,w));
                b[u][v] = true;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        int x, y, w; scanf("%d %d %d", &x, &y, &w);
        bfs(x,y,w);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, a[i][j]);
    printf("%d\n", ans);
    return 0;
}

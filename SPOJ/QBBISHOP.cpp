#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 209;
const int dx[] = {1,1,-1,-1};
const int dy[] = {-1,1,1,-1};

int n, m, p, q, s, t, a[N][N]={};
bool b[N][N]={};

int canGo(int u, int v){
    return 1 <= u && u <= n && 1 <= v && v <= n && !b[u][v] && !a[u][v];
}

void BFS(){
    queue<ii> qu;
    qu.push(ii(p,q)); b[p][q] = true;
    while(!qu.empty()){
        ii u = qu.front(); qu.pop();
        for(int i=0; i<4; i++){
            for(int k=1; k<=n; k++){
                ii v(u.x + dx[i]*k, u.y + dy[i]*k);
                if(canGo(v.x,v.y)){
                    a[v.x][v.y] = a[u.x][u.y] + 1;
                    if(v == ii(s,t)) return;
                    qu.push(v);
                }else break;
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&p,&q,&s,&t);
    for(int i=0; i<m; i++){
        int x, y; scanf("%d%d",&x,&y);
        b[x][y] = true;
    }

    if(!m){
        if(abs(p-s) == abs(q-t)) printf("1\n");
        else printf("2\n");
        return 0;
    }

    BFS();
    printf("%d\n",!a[s][t]? -1:a[s][t]);
    return 0;
}

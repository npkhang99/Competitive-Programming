#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N=209;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, m, a[N][N]={}, b[N][N]={};
vector<ii> ans(0), conn(0);

int canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m && !a[u][v] && !b[u][v];
}

void BFS(ii s){
    queue<ii> q; q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(b[u.x][u.y]) continue;
        b[u.x][u.y] = 1; conn.push_back(u);
        for(int i=0; i<4; i++){
            ii v = ii(u.x + dx[i], u.y + dy[i]);
            if(canGo(v.x,v.y)) q.push(v);
        }
    }
    if(conn.size() > ans.size()) ans.clear(), ans = conn;
    conn.clear();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("LTBien.inp","r",stdin);
    // freopen("LTBien.out","w",stdout);
    cin>> n>> m;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>> a[i][j];

    for(int i=0; i<n; i++){
        if(!a[i][0] && !b[i][0]) BFS(ii(i,0));
        if(!a[i][m-1] && !b[i][m-1]) BFS(ii(i,m-1));
    }
    for(int i=0; i<m; i++){
        if(!a[0][i] && !b[0][i]) BFS(ii(0,i));
        if(!a[n-1][i] && !b[n-1][i]) BFS(ii(n-1,i));
    }

    sort(ans.begin(),ans.end());
    cout<< ans.size()<< '\n';
    for(int i=0; i<ans.size(); i++) cout<< ans[i].x+1<< ' '<< ans[i].y+1<< '\n';
    return 0;
}

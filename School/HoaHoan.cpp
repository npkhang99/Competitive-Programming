#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N=1009;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, m, d[N][N]={}, b[N][N]={}, df[N][N]={}, bf[N][N]={};
char a[N][N]={};
vector<ii> F;
ii s;

int canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m && a[u][v] == '.';
}

int canSpread(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m && a[u][v] != '#';
}

void BFS(){
    queue<ii> q;
    q.push(s); d[s.x][s.y] = 1;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(b[u.x][u.y]) continue;
        b[u.x][u.y] = 1;
        for(int i=0; i<4; i++){
            ii v = ii(u.x + dx[i], u.y + dy[i]);
            if(canGo(v.x,v.y) && d[v.x][v.y] > d[u.x][u.y] + 1)
                d[v.x][v.y] = d[u.x][u.y] + 1, q.push(v);
        }
    }

    for(int i=0; i<F.size(); i++) q.push(F[i]), df[F[i].x][F[i].y] = 1;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(bf[u.x][u.y]) continue;
        bf[u.x][u.y] = 1;
        for(int i=0; i<4; i++){
            ii v = ii(u.x + dx[i], u.y + dy[i]);
            if(canSpread(v.x,v.y) && df[v.x][v.y] > df[u.x][u.y] + 1)
                df[v.x][v.y] = df[u.x][u.y] + 1, q.push(v);
        }
    }
}

void ex(int a[N][N]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout<< a[i][j]<< ' ';
        cout<< '\n';
    }
    cout<< '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("HoaHoan.inp","r",stdin);
    // freopen("HoaHoan.out","w",stdout);
    cin>> n>> m;
    for(int i=0; i<n; i++) cin>> a[i];

    for(int i=0; i<n; i++) for(int j=0; j<m; j++){
        if(a[i][j] == 'F') F.push_back(ii(i,j));
        else if(a[i][j] == 'J') s = ii(i,j);
        d[i][j] = df[i][j] = 10E8;
    }

    BFS();

    int ans = 10E8;
    for(int i=0; i<n; i++){
        if(d[i][0] != 10E8 && d[i][0] < df[i][0]) ans = min(ans, d[i][0]);
        if(d[i][m-1] != 10E8 && d[i][m-1] < df[i][m-1]) ans = min(ans, d[i][m-1]);
    }
    for(int i=0; i<m; i++){
        if(d[0][i] != 10E8 && d[0][i] < df[0][i]) ans = min(ans, d[0][i]);
        if(d[n-1][i] != 10E8 && d[n-1][i] < df[n-1][i]) ans = min(ans, d[n-1][i]);
    }

    cout<< (ans == 10E8? -1:ans)<< '\n';
    return 0;
}

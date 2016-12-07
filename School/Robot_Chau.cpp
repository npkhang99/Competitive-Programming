#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define x first
#define y second

const int N=1509;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, a[N][N]={}, d[N][N]={};
ii s, t;

ii find(int x, int flag){
    if(flag){
        for(int i=n-1; i>=0; i--)
            if(!a[x][i]) return ii(x,i);
        return ii(-1,-1);
    }
    for(int i=0; i<n; i++)
        if(!a[x][i]) return ii(x,i);
    return ii(-1,-1);
}

int canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < n && a[u][v] == 0;
}

void BFS(){
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push(iii(0,s)); d[s.x][s.y] = 0;
    while(!q.empty()){
        int du = q.top().first;
        ii u = q.top().second;
        q.pop();
        if(u == t) break;
        if(du > d[u.x][u.y]) continue;
        for(int i=0; i<4; i++){
            ii v = ii(u.x+dx[i], u.y+dy[i]);
            if(canGo(v.x,v.y) && d[u.x][u.y] + 1 < d[v.x][v.y])
                d[v.x][v.y] = d[u.x][u.y]+1, q.push(iii(d[v.x][v.y],v));
        }
    }
    cout<< (d[t.x][t.y] == 10E8? -1:d[t.x][t.y])<< '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Robot.inp","r",stdin);
    // freopen("Robot.out","w",stdout);
    cin>> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>> a[i][j], d[i][j] = 10E8;

    s = find(0,0);
    t = find(n-1,1);
    if(s == ii(-1,-1) || t == ii(-1,-1)){
        cout<< "-1\n";
        return 0;
    }
    BFS();
    return 0;
}

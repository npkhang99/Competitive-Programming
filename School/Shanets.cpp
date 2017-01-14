#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 2009;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

struct rect{
    int top_x, top_y, bot_x, bot_y;
}a[N];

int n, b[N][N]={}, d[N][N]={};
rect R;

void shift(rect &a){
    a.top_x += 1001;
    a.top_y += 1001;
    a.bot_x += 1001;
    a.bot_y += 1001;
}

int bfs(ii s){
    int size = 0;
    queue<ii> q;
    q.push(s);
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(b[u.x][u.y]) continue;
        b[u.x][u.y] = 1;
        size += 1;
        for(int i=0; i<4; i++){
            ii v(u.x + dx[i], u.y + dy[i]);
            if(!b[v.x][v.y] && d[v.x][v.y]) q.push(v);
        }
    }
    return size;
}

int main(){
    // freopen("Shanets.inp","r",stdin);
    // freopen("Shanets.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d%d",&a[i].top_x,&a[i].top_y,&a[i].bot_x,&a[i].bot_y);

    R = a[0];
    for(int i=1; i<n; i++){
        R.top_x = min(R.top_x, a[i].top_x);
        R.top_y = max(R.top_y, a[i].top_y);
        R.bot_x = max(R.bot_x, a[i].bot_x);
        R.bot_y = min(R.bot_y, a[i].bot_y);
    }

    printf("%d %d %d %d\n%d\n",R.top_x,R.top_y,R.bot_x,R.bot_y,(R.top_x - R.bot_x)*(R.bot_y - R.top_y));
    shift(R);
    for(int i=0; i<n; i++)
        shift(a[i]);

    for(int i=0; i<n; i++){
        for(int j=a[i].bot_y; j<a[i].top_y; j++){
            b[j][a[i].top_x] += 1;
            b[j][a[i].bot_x] -= 1;
        }
    }

    for(int i=R.top_y-1; i>=R.bot_y; i--){
        int v = 0;
        for(int j=R.top_x; j<=R.bot_x; j++){
            v += b[i][j];
            d[i][j] = v;
        }
    }

    memset(b,0,sizeof b);

    int C = 0, D = 0;
    for(int i=R.top_y; i>=R.bot_y; i--)
        for(int j=R.top_x; j<=R.bot_x; j++)
            if(d[i][j] && !b[i][j]){
                int area = bfs(ii(i,j));
                C += area;
                D = max(D, area);
            }
    printf("%d %d\n",C,D);
    return 0;
}

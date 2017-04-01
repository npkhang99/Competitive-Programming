// PreVOI 2017 - Day 1
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};

int n, m;
bool b[N][N];
char a[N][N];

bool canGo(int u, int v){
    return 0 <= u && u < n && 0 <= v && v < m;
}

void fill(char c, ii s){
    queue<ii> q; q.push(s); a[s.first][s.second] = c;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        for(int i=0; i<4; i++){
            ii v(u.first + dx[i], u.second + dy[i]);
            if(canGo(v.first, v.second) && a[v.first][v.second] != c){
                a[v.first][v.second] = c;
                q.push(v);
            }
        }
    }
}

int bfs(ii s){
    int cnt = 0;
    queue<ii> q; q.push(s); b[s.first][s.second] = true;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(!b[u.first][u.second]) continue;
        ++cnt;
        for(int i=0; i<4; i++){
            ii v(u.first + dx[i], u.second + dy[i]);
            if(canGo(v.first, v.second) && a[v.first][v.second] == a[s.first][s.second] && !b[v.first][v.second]){
                b[v.first][v.second] = true;
                q.push(v);
            }
        }
    }
    return cnt;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0);
    // freopen("FFill.inp","r",stdin);
    // freopen("FFill.out","w",stdout);
    // cin>> n>> m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        // cin>> a[i];
        scanf(" %s",a[i]);

    int q, last_cnt = -1, last_ans = -1;
    // cin>> q;
    scanf("%d",&q);
    for(int i=0; i<q; i++){
        if(last_cnt == 1){
            // cout<< last_cnt<< " "<< last_ans<< '\n';
            printf("%d %d\n", last_cnt, last_ans);
            continue;
        }
        char c; int x, y; cin>> c>> x>> y;
        if(c != a[--x][--y]) fill(c, ii(x,y));
        else if(i > 0){
            // cout<< last_cnt<< " "<< last_ans<< '\n';
            printf("%d %d\n", last_cnt, last_ans);
            continue;
        }
        memset(b, false, sizeof b);
        int cnt = 0, ans = 0;
        for(x = 0; x<n; x++)
            for(y = 0; y<m; y++)
                if(!b[x][y]) ++cnt, ans = max(ans, bfs(ii(x,y)));
        // cout<< cnt<< " "<< ans<< '\n';
        last_cnt = cnt; last_ans = ans;
        printf("%d %d\n", last_cnt, last_ans);
    }
    return 0;
}

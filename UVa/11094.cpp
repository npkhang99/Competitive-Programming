#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef pair<int,int> ii;

const int N = 29;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char a[N][N];
bool visited[N][N] = {};
char land;

bool can_go(ii u) {
    return 0 <= u.first && u.first < n && 0 <= u.second && u.second < m && !visited[u.first][u.second] && a[u.first][u.second] == land;
}

int bfs(ii s) {
    queue<ii> q;
    q.push(s);
    visited[s.first][s.second] = true;
    int size = 0;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        ++size;
        for (int i = 0; i < 4; i++) {
            ii v = ii(u.first + dx[i], u.second + dy[i]);
            v.second = (v.second + m) % m;
            if (can_go(v)) {
                q.push(v);
                visited[v.first][v.second] = true;
            }
        }
    }
    return size;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
                cin >> a[i][j];
            }
        }

        ii s;
        cin >> s.first >> s.second;

        land = a[s.first][s.second];

        bfs(s);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // fprintf(stderr, "%d %d - %c %d\n", i, j, a[i][j], visited[i][j]);
                if (a[i][j] == land && !visited[i][j]) {
                    int t = bfs(ii(i, j));
                    // fprintf(stderr, "%d %d %d\n", i, j, t);
                    ans = max(ans, t);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

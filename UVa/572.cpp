#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef pair<int,int> ii;

const int N = 109;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

int n, m;
char a[N][N];
bool visited[N][N] = {};

bool can_go(ii u) {
    return 0 <= u.first && u.first < n && 0 <= u.second && u.second < m && !visited[u.first][u.second] && a[u.first][u.second] == '@';
}

void bfs(ii s) {
    queue<ii> q;
    q.push(s);
    visited[s.first][s.second] = true;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            ii v = ii(u.first + dx[i], u.second + dy[i]);
            if (can_go(v)) {
                q.push(v);
                visited[v.first][v.second] = true;
            }
        }
    }
}

int main() {
    while (cin >> n >> m, n * m > 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
                cin >> a[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '@' && !visited[i][j]) {
                    bfs(ii(i, j));
                    ++ans;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}

#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef pair<int,int> ii;

class FriendlyRooks {
private:
    int n, m;
    int cnt = 0;
    vector<vector<int>> color;

    void dfs(ii s, int c, vector<string> &a) {
        color[s.first][s.second] = c;
        for (int x = s.first + 1; x < n; x++) {
            if (a[x][s.second] == 'R') {
                if (color[x][s.second] == 0) {
                    dfs(ii(x, s.second), c, a);
                }
                break;
            }
        }
        
        for (int x = s.first - 1; x >= 0; x--) {
            if (a[x][s.second] == 'R') {
                if (color[x][s.second] == 0) {
                    dfs(ii(x, s.second), c, a);
                }
                break;
            }
        }
        
        for (int y = s.second + 1; y < m; y++) {
            if (a[s.first][y] == 'R') {
                if (color[s.first][y] == 0) {
                    dfs(ii(s.first, y), c, a);
                }
                break;
            }
        }
        
        for (int y = s.second - 1; y >= 0; y--) {
            if (a[s.first][y] == 'R') {
                if (color[s.first][y] == 0) {
                    dfs(ii(s.first, y), c, a);
                }
                break;
            }
        }
    }
public:
    int getMinFriendlyColoring(vector<string> board) {
        n = board.size();
        m = board[0].length();
         
        color.resize(n);
        for (int i = 0; i < n; i++) {
            color[i].resize(m);
        }
         
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'R' && color[i][j] == 0) {
                    dfs(ii(i, j), ++cnt, board);
                }
            }
        }
         
        return cnt;
    }
};

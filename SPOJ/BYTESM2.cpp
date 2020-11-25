#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h + 1, vector<int>(w + 2, 0));
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<int>> dp(h + 1, vector<int>(w + 2, 0));
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + a[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i <= w; i++) {
            ans = max(ans, dp[h][i]);
        }

        cout << ans << endl;
    }
    return 0;
}

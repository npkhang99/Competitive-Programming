#include <bits/stdc++.h>
using namespace std;

int memo[2][59] = {};
vector<int> a;

class ZigZag {
public:
    int dp(int p, int t) {
        if (p == 0) {
            return 1;
        }

        if (~memo[t][p]) {
            return memo[t][p];
        }

        if ((a[p - 1] - a[p]) * (t == 0 ? -1 : 1) > 0) {
            return memo[t][p] = max(dp(p - 1, t), dp(p - 1, 1 - t) + 1);
        } else {
            return memo[t][p] = dp(p - 1, t);
        }
    }

    int longestZigZag(vector<int> sequence) {
        a = sequence;
        memset(memo, -1, sizeof memo);
        return max(dp((int) a.size() - 1, 0), dp((int) a.size() - 1, 1));
    }
};

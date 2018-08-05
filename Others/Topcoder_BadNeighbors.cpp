#include <bits/stdc++.h>
using namespace std;

int dp[49] = {};
vector<int> a;

class BadNeighbors {
public:
    int dp(int p, bool take_last) {
        if (p == 0) {
            if (take_last == true) {
                return 0;
            }
            return a[p];
        }

        if (p < 0) {
            return 0;
        }

        if (~memo[p]) {
            return memo[p];
        }
    }

    int maxDonations(vector<int> donations) {
        a = donations;
        n = (int) a.size();
        memset(memo, -1, sizeof memo);
        return max(dp(a.size() - 1, true), dp(a.size() - 1, false));
    }
};

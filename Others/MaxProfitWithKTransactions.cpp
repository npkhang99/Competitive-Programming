// AlgoExpert - Max Profit With K Transactions
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(vector<vector<vector<int>>> &memo, vector<int> &prices, int p, int left, int state) {
    if (p == prices.size() || left == 0) {
        return 0;
    }

    if (memo[p][left][state] != -1) {
        return memo[p][left][state];
    }

    int tmp = 0;
    for (int i = p; i < (int) prices.size(); i++) {
        tmp = max(tmp, dp(memo, prices, i + 1, left - (state == 1), 1 - state) + prices[i] * (state ? 1 : -1));
    }

    return memo[p][left][state] = tmp;
}

int maxProfitWithKTransactions(vector<int> prices, int k) {
    vector<vector<vector<int>>> memo;
    memo.resize(prices.size());
    for (int i = 0; i < prices.size(); i++) {
        memo[i].resize(k + 1);
        for (int j = 0; j <= k; j++) {
            memo[i][j].resize(2, -1);
        }
    }

    int ans = dp(memo, prices, 0, k, 0);
    cerr << ans << endl;

    return ans;
}

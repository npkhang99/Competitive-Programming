#include <bits/stdc++.h>
using namespace std;

vector<int> kahn(vector<vector<int>>& adj, vector<int>& in_degree) {
    queue<int> q;
    vector<int> ans(in_degree.size(), 0);

    for (int i = 0; i < in_degree.size(); i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int boss = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ans[u] = boss;
        boss = u;

        for (int v : adj[u]) {
            in_degree[v]--;

            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n, vector<int>());
    vector<int> in_degree(n, 0);
    
    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            x--;
            adj[i].push_back(x);
            in_degree[x]++;
        }
    }

    for (int e : kahn(adj, in_degree)) {
        cout << e + 1 << endl;
    }

    return 0;
}

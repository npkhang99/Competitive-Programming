#include <bits/stdc++.h>
using namespace std;

const int N = 10009;

int n, m, in_degree[N] = {};
vector<int> adj[N] = {};

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in_degree[y] += 1;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> visited(n + 1, false);
    
    for (int i = 1; i<= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        ans.push_back(u);

        for (int v : adj[u]) {
            in_degree[v] -= 1;
            if (!visited[v] && in_degree[v] == 0) {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    if ((int) ans.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    else {
        cout << "Sandro fails.\n";
    }
    return 0;
}

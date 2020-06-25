#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 100009;

int n, color[N] = {};
vector<ii> adj[N];

int dfs(int u, int prev_color) {
    int c = 1;
    for (ii edge : adj[u]) {
        int v = edge.first;
        int id = edge.second;
        if (!color[id]) {
            while (c == prev_color) {
                c += 1;
            }
            color[id] = c;
            dfs(v, c);
            c += 1;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(ii(v, i));
        adj[v].push_back(ii(u, i));
    }

    dfs(1, 0);

    int k = *max_element(color, color + n);
    cout << k << endl;

    for (int i = 0; i < n - 1; i++) {
        cout << color[i] << endl;
    }
    return 0;
}

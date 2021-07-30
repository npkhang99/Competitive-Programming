#include <bits/stdc++.h>
using namespace std;

vector<int> topo(vector<vector<int>>& adj) {
    vector<int> in_degree(26, 0);
    for (int i = 0; i < 26; i++) {
        for (int c : adj[i]) {
            in_degree[c]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topo;
}

int main() {
    int n, longest_word_legth = 0;
    vector<string> words;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
        longest_word_legth = max(longest_word_legth, (int) word.length());
    }

    vector<vector<int>> adj(26);
    vector<bool> relation_built(n, false);
    relation_built[0] = true;

    for (int p = 0; p < longest_word_legth; p++) {
        for (int i = 1; i < n; i++) {
            if (relation_built[i]) {
                continue;
            }

            if (words[i - 1].length() > p && words[i].length() <= p) {
                cout << "Impossible" << endl;
                return 0;
            }

            if (words[i].length() <= p) {
                continue;
            }

            if (words[i - 1].length() > p && words[i - 1][p] != words[i][p]) {
                adj[words[i - 1][p] - 'a'].push_back(words[i][p] - 'a');
                relation_built[i] = true;
            }
        }
    }

    auto sorted = topo(adj);
    
    if (sorted.size() < 26) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int v : sorted) {
        cout << char('a' + v);
    }

    cout << endl;
    
    return 0;
}

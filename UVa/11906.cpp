#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 109;

int n, m, r, c;
bool visited[N][N] = {}, water[N][N] = {};
vector<ii> d;

bool inside(ii p) {
    return 0 <= p.first && p.first < n && 0 <= p.second && p.second < m;
}

bool valid(ii p) {
    return inside(p) && !water[p.first][p.second] && !visited[p.first][p.second];
}

void bfs() {
    queue<ii> q;
    visited[0][0] = true;
    q.push(ii(0, 0));

    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            ii v(u.first + d[i].first, u.second + d[i].second);
            if (valid(v)) {
                visited[v.first][v.second] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int TC;
    scanf("%d" ,&TC);
    for (int test = 1; test <= TC; test++) {
        scanf("%d %d %d %d", &n, &m, &r, &c);
        
        d.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = water[i][j] = false;
            }
        }

        d.push_back(ii(-r, -c));
        d.push_back(ii(-r, c));
        d.push_back(ii(r, -c));
        d.push_back(ii(r, c));
        d.push_back(ii(-c, -r));
        d.push_back(ii(-c, r));
        d.push_back(ii(c, -r));
        d.push_back(ii(c, r));

        int w;
        scanf("%d", &w);
        for (int i = 0; i < w; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            water[x][y] = true;
        }

        bfs();

        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    continue;
                }

                int cnt = 0;
                set<ii> checked;
                for (int k = 0; k < 8; k++) {
                    ii p(i + d[k].first, j + d[k].second);
                    // fprintf(stderr, "%d %d -> %d %d\n", i, j, p.first, p.second);
                    if (inside(p) && visited[p.first][p.second] && checked.find(p) == checked.end()) {
                        checked.insert(p);
                        ++cnt;
                    }
                }

                if (cnt % 2 == 0) {
                    ++even;
                }
                else {
                    ++odd;
                }
            }
        }

        printf("Case %d: %d %d\n", test, even, odd);
    }
    return 0;
}

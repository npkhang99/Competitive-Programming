// USACO 2016 December Contest, Gold
// Problem 3. Lasers and Mirrors
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,bool> Line;

#define val first
#define horizontal second

const int N = 100009;

int n, x1, y1, x2, y2;
map<Line,int> dist;
map<int, vector<int> > xtoY, ytoX;
queue<Line> q;

int main() {
    // freopen("lasers.in","r",stdin);
    // freopen("lasers.out","w",stdout);
    scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);

    dist[Line(y1,true)] = 0;
    q.push(Line(y1,true));
    dist[Line(x1,false)] = 0;
    q.push(Line(x1,false));

    for(int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        xtoY[x].push_back(y);
        ytoX[y].push_back(x);
    }

    int ans = 0;
    while(!q.empty()) {
        Line curr = q.front(); q.pop();

        if(curr.horizontal == true && curr.val == y2) {
            ans = dist[curr];
            break;
        }
        if(curr.horizontal == false && curr.val == x2) {
            ans = dist[curr];
            break;
        }

        map<int, vector<int> > *source;
        if(curr.horizontal == true) source = &ytoX;
        else source = &xtoY;

        if((*source).find(curr.val) != (*source).end()) {
            for(int i = 0; i < (*source)[curr.val].size(); i++) {
                int dest = (*source)[curr.val][i];
                Line nextLine(dest, !curr.horizontal);
                if(dist.find(nextLine) == dist.end()) {
                    dist[nextLine] = dist[curr] + 1;
                    q.push(nextLine);
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

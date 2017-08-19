#include <bits/stdc++.h>
using namespace std;

struct Query {
    int x1, x2, y1, y2, t;
    void read(int i){
        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
    }
};

const int N = 100009;

int n, q, c, cnt[109][109][19]={};
vector<Query> query;

int main(){
    scanf("%d %d %d", &n, &q, &c);
    query.resize(q);
    for(int i = 0; i < n; i++){
        int x, y, s; scanf("%d %d %d", &x, &y, &s);
        cnt[x][y][s]++;
    }
    for(int i = 0; i < q; i++)
        query[i].read(i);

    for(int i = 1; i < 101; i++)
        for(int j = 1; j < 101; j++)
            for(int k = 0; k < 11; k++)
                cnt[i][j][k] += cnt[i][j-1][k];

    for(Query q : query){
        long long total = 0;
        for(int x = q.x1; x <= q.x2; x++){
            for(int k = 0; k <= 10; k++)
                total += (cnt[x][q.y2][k] * ((k + q.t) % (c+1))) - (cnt[x][q.y1-1][k] * ((k + q.t) % (c+1)));
        }
        printf("%lld\n", total);
    }
    return 0;
}

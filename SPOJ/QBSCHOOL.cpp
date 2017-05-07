#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N = 5009;

int n, m, d[N]={};
long long memo[N]={};
vector<ii> a[N];

int dijkstra(){
    priority_queue<ii> q;
    d[1] = 0; q.push(ii(0,1));
    while(!q.empty()){
        int u = q.top().second,
            du = -q.top().first;
        q.pop();

        if(du > d[u]) continue;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first,
                c = a[u][i].second;
            if(d[v] > d[u] + c){
                d[v] = d[u] + c;
                q.push(ii(-d[v],v));
            }
        }
    }
    return -1;
}

long long dp(int u){
    if(u == n) return 1;
    if(memo[u] != -1) return memo[u];

    long long temp = 0;
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i].first,
            c = a[u][i].second;
        if(d[v] == d[u] + c){
            temp += dp(v);
        }
    }
    return memo[u] = temp;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int k, x, y, z; scanf("%d %d %d %d", &k, &x, &y, &z);
        a[x].push_back(ii(y,z));
        if(k == 2){
            a[y].push_back(ii(x,z));
        }
    }

    memset(d, 0x3f, sizeof d);
    memset(memo, -1, sizeof memo);

    dijkstra();

    printf("%d %lld\n", d[n], dp(1));
    return 0;
}

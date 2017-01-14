#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 20009;

int n, m, k, q, d[N]={}, b[N]={};
vector<ii> a[N];

int dijkstra(int s, int t){
    priority_queue<ii> q; q.push(ii(0,s));
    for(int i=1; i<=n; i++) d[i] = 1e9;
    d[s] = 0;
    while(!q.empty()){
        int u = q.top().second, du = -q.top().first; q.pop();
        // fprintf(stderr, "%d %d\n", u,du);
        if(du > d[u]) continue;
        if(u == t) return du;
        for(int i=0; i<a[u].size(); i++){
            ii v = a[u][i];
            if(b[u] != b[v.first] && du + v.second < d[v.first]){
                d[v.first] = du + v.second;
                q.push(ii(-d[v.first], v.first));
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("ABCAir.inp","r",stdin);
    // freopen("ABCAir.out","w",stdout);
    cin>> n>> m>> k>> q;
    for(int i=0; i<m; i++){
        int x,y,v; cin>> x>> y>> v;
        a[x].push_back(ii(y,v));
    }

    for(int i=0; i<k; i++){
        int x; cin>> x;
        b[x] = 1;
    }

    int cnt = 0;
    long long ans = 0;
    while(q--){
        int x,y; cin>> x>> y;
        int c = dijkstra(x,y);
        if(~c) cnt++, ans += c;
    }

    cout<< cnt<< '\n'<< ans<< '\n';
    return 0;
}

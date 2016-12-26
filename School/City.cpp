#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N = 509;

int n, m, T, W, d[N][N]={};
vector<iii> a[N];

int dijkstra(){
    priority_queue<iii, vector<iii>, greater<iii> > q;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=T; j++)
            d[i][j] = 1e9;
    q.push(iii(ii(W*T, 0), 1)); d[1][T] = W*T;
    while(!q.empty()){
        int u = q.top().second;
        ii du = q.top().first;
        q.pop();
        // cerr<< u<< " "<< du.first<< " "<< du.first - W*(T - du.second)<< " "<< du.second<< endl;
        if(u == n) return du.first;
        if(d[u][du.second] < du.first) continue;
        for(int i=0; i<a[u].size(); i++){
            ii dv = a[u][i].first;
            for(int k=1; k<=T; k++){
                int v = k%2? a[u][i].second:u;
                if(du.second + dv.second*k <= T && du.first - W*(T - du.second) + dv.first*k + W*(T - (du.second + dv.second*k)) < d[v][du.second + dv.second*k]){
                    d[v][du.second + dv.second*k] = du.first - W*(T - du.second) + dv.first*k + W*(T - (du.second + dv.second*k));
                    q.push(iii(ii(du.first - W*(T - du.second) + dv.first*k + W*(T - (du.second + dv.second*k)), du.second + dv.second*k), v));
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("City.inp","r",stdin);
    // freopen("City.out","w",stdout);
    cin>> n>> m>> T>> W;
    for(int i=0; i<m; i++){
        int x,y,t,c; cin>> x>> y>> t>> c;
        a[x].push_back(iii(ii(c,t),y));
        a[y].push_back(iii(ii(c,t),x));
    }

    cout<< dijkstra()<< '\n';
    return 0;
}

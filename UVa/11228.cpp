#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define x first
#define y second

const int N = 1009;

int n, r, state_count, par[N]={}, ranking[N]={}, par_state[N]={}, state_ranking[N]={};
ii a[N];
vector<iii> edges;

int dist(int i, int j){
    return (a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y);
}

int state(int p){
    return p == par_state[p]? p:state(par_state[p]);
}

bool join_state(int u, int v){
    u = state(u);
    v = state(v);
    if(u == v) return false;
    state_count--;
    if(state_ranking[u] <= state_ranking[v]){
        par_state[u] = v;
        if(state_ranking[u] == state_ranking[v])
            state_ranking[v]++;
    }else par_state[v] = u;
    return true;
}

int root(int p){
    return p == par[p]? p:root(par[p]);
}

bool join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return false;
    if(ranking[u] <= ranking[v]){
        par[u] = v;
        if(ranking[u] == ranking[v])
            ranking[v]++;
    }else par[v] = u;
    return true;
}

int main(){
    int TC; scanf("%d", &TC);
    for(int TEST=1; TEST <= TC; TEST++){
        scanf("%d %d", &n, &r);
        for(int i=1; i<=n; i++){
            scanf("%d %d", &a[i].x, &a[i].y);
            par_state[i] = par[i] = i;
            state_ranking[i] = ranking[i] = 0;
        }

        edges.clear(); state_count = n;

        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(dist(i,j) <= r*r) join_state(i,j);
                edges.push_back(iii(dist(i,j), ii(i,j)));
            }
        }

        sort(edges.begin(), edges.end());

        int cnt = 0;
        double road = 0, railway = 0;
        for(int i=0; i<edges.size() && cnt != n-1; i++){
            int u = edges[i].second.x,
                v = edges[i].second.y,
                cost = edges[i].first;
            if(join(u,v)){
                if(cost <= r*r) road += sqrt(cost);
                else railway += sqrt(cost);
                cnt++;
            }
        }

        printf("Case #%d: %d %d %d\n", TEST, state_count, (int)round(road), (int)round(railway));
    }
    return 0;
}

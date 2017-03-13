#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;

int n, m, d[N]={};
vector<ii> adj[N];

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; i++)
            adj[i].clear();

        while(m--){
            int x, y, v; scanf("%d %d %d", &x, &y, &v);
            adj[x].push_back(ii(y,v));
        }

        memset(d, 0x3f, sizeof d);
        d[0] = 0;
        for(int i=1; i<n; i++){
            for(int u=0; u<n; u++)
                for(ii v : adj[u])
                    d[v.first] = min(d[v.first], d[u] + v.second);
        }

        int negative_cycle = false;
        for(int u=0; u<n; u++)
            for(ii v : adj[u])
                if(d[u] + v.second < d[v.first]) negative_cycle = true;

        printf("%s\n", negative_cycle? "possible":"not possible");
    }
    return 0;
}

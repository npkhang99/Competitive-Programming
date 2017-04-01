#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 309;

int n, c[N]={}, ans = 0;
bool have_access[N]={};
ii d[N]={};
vector<ii> adj[N];

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &d[i].first);
        d[i].second = i+1;
        c[i+1] = d[i].first;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            int x; scanf("%d", &x);
            if(x) adj[i].push_back(ii(j,x));
        }

    sort(d, d+n);
    for(int i=0; i<n; i++)
        if(!have_access[d[i].second]){
            dfs(d[i].second);
        }

    printf("%d\n", ans);
    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 25009;

struct DSU{
    int ranking[N], par[N], numSet;

    int root(int p){ return par[p]==p? p:root(par[p]); }
    bool sameSet(int u, int v){ return root(u) == root(v); }
    bool join(int u, int v){
        u = root(u); v = root(v);
        if(u == v) return false;
        numSet--;
        if(ranking[u] <= ranking[v]){
            par[u] = v;
            if(ranking[u] == ranking[v]) ranking[v]++;
        }else par[v] = u;
        return true;
    }

    DSU(int n){
        for(int i=0; i<n; i++)
            par[i] = i, ranking[i] = 0;
        numSet = n;
    }
};

int n, m;
iii a[N]={};
vector<int> b;

int main(){
    while(scanf("%d%d",&n,&m), n || m){
        for(int i=0; i<m; i++)
            scanf("%d%d%d", &a[i].second.first, &a[i].second.second, &a[i].first);
        sort(a,a+m);
        DSU dsu(n);
        int cnt=0; b.clear();
        for(int i=0; i<m; i++)
            if(n - dsu.numSet == n-1 || !dsu.join(a[i].second.first, a[i].second.second)) b.push_back(a[i].first);
        
        for(int i=0; i<b.size(); i++)
            printf("%d%c", b[i], i == b.size()-1? '\n':' ');
        if(b.empty()) printf("forest\n");
    }
    return 0;
}

// Simple Union-Find Disjoin Set
#include <vector>

typedef vector<int> vi;

class DisjoinSet{
private:
    vi par, size;
public:
    int root(int i){ return par[i] == i? p:par[i] = root(par[i]); }
    void joint(int u, int v){
        u = root(u);
        v = root(v);
        if(u == v) return;
        if(size[u] < size[v]) swap(u,v);
        size[u] += size[v];
        par[v] = u;
    }

    DisjoinSet(int _n = 0){
        size.assign(_n+1, 1); par.assign(_n+1, 0);
        for(int i=1; i<=_n; i++)
            par[i] = i;
    }
}

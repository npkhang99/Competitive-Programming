// Simple DSUF
#include <vector>

typedef vector<int> vi;

class DisjoinSet{
private:
    vi par, setSize, setRank;
public:
    int root(int i){ return par[i] == i? p:par[i] = root(par[i]); }
    void join(int u, int v){
        u = root(u);
        v = root(v);
        if(u == v) return;
        if (setRank[x] > setRank[y]) { par[y] = x; setSize[x] += setSize[y]; }
        else{
            par[x] = y; setSize[y] += setSize[x];
            if (setRank[x] == setRank[y]) setRank[y]++;
        }
    }

    DisjoinSet(int _n = 0){
        setSize.assign(_n+1, 1); par.assign(_n+1, 0); setRank.assign(_n+1, 0);
        for(int i=1; i<=_n; i++)
            par[i] = i;
    }
}

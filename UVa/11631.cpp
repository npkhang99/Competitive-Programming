#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 200009;

int n, m, par[N]={}, size[N]={}, setRank[N]={};
vector<iii> a;

int root(int p){ return p == par[p]? p:root(par[p]); }

void join(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v) return;
    if(size[u] < size[v]) swap(u,v);
    if(setRank[x] > setRank[y]) { par[y] = x; setSize[x] += setSize[y]; }
    else{
        par[x] = y; setSize[y] += setSize[x];
        if (setRank[x] == setRank[y]) setRank[y]++;
    }
}

int main(){
    while(scanf("%d%d",&n,&m), n || m){
        a.clear();
        for(int i=0; i<n; i++)
            par[i] = i, size[i] = 1, setRank[i] = 0;

        int total = 0;
        for(int i=0; i<m; i++){
            int x,y,z; scanf("%d%d%d",&x,&y,&z);
            total += z;
            a.push_back(iii(z,ii(x,y)));
        }

        sort(a.begin(), a.end());
        int mst = 0, cnt = 0;
        for(int i=0; i<m; i++)
            if(root(a[i].second.first) != root(a[i].second.second)){
                join(a[i].second.first,a[i].second.second);
                mst += a[i].first;
                if(++cnt == n-1) break;
            }
        printf("%d\n",total-mst);
    }
    return 0;
}

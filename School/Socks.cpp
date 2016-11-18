#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int N=200009;

int n, m, k, a[N]={}, c[N]={}, par[N]={}, Rank[N]={};
bool b[N]={}, use[N]={};
map<int,vector<int> > set;
map<int,int> cnt;

int root(int p){ return p==par[p]? p:root(par[p]); }

void joint(int p, int q){
    int x = root(p), y = root(q);
    if(x == y) return;
    if(Rank[x] > Rank[y]) par[y] = x;
    else{
        par[x] = y;
        if(Rank[x] == Rank[y]) Rank[y]+=1;
    }
}

int findSet(int p){
    if(p == par[p]){
        if(!b[p]) set[p].push_back(p); b[p] = 1;
        return p;
    }
    int r = findSet(par[p]);
    if(!b[p]) set[r].push_back(p); b[p] = 1;
    return r;
}

int main(){
    freopen("Socks.inp","r",stdin);
    freopen("Socks.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++) scanf("%d",&c[i]);

    for(int i=1; i<=n; i++) par[i] = i;
    for(int i=0; i<m; i++){
        int x, y; scanf("%d%d",&x,&y);
        joint(x,y); use[x] = use[y] = 1;
    }

    for(int i=1; i<=n; i++)
        if(use[i] && !b[i]) findSet(i);

    int ans = 0;
    for(map<int,vector<int> >::iterator it=set.begin(); it!=set.end(); it++){
        cnt.clear();
        int size = (*it).second.size(), maxOccur = 0;
        for(int i=0; i<size; i++){
            int color = (*it).second[i];
            cnt[c[color]] += 1;
        }

        for(map<int,int>::iterator it2=cnt.begin(); it2!=cnt.end(); it2++)
            maxOccur = max(maxOccur,(*it2).second);
        ans += size - maxOccur;
    }
    printf("%d\n",ans);
    return 0;
}

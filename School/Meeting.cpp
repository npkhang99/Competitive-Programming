#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N=209;

int n, m, k, dt[N]={}, dm[N]={};
vector<iii> a[N];

int main(){
    // freopen("Meeting.inp","r",stdin);
    // freopen("Meeting.out","w",stdout);
    scanf("%d%d%d",&k,&n,&m);
    for(int i=0; i<m; i++){
        int x,y,t,v; scanf("%d%d%d%d",&x,&y,&t,&v);
        a[x].push_back(iii(y,ii(t,v)));
        a[y].push_back(iii(x,ii(t,v)));
    }
    BFS();
    return 0;
}

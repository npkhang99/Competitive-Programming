#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef pair<double,ii> dii;

const int N = 109;

int n, par[N]={}, ranking[N]={};
dd b[N]={};
dii a[N*N]={};

double sqr(double x){ return x*x; }

int root(int p){ return p == par[p]? p:root(par[p]); }

bool join(int u, int v){
    u = root(u); v = root(v);
    if(u == v) return false;
    if(ranking[u] <= ranking[v]){
        par[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
    }else par[v] = u;
    return true;
}

double dist(dd x, dd y){
    return sqrt(sqr(x.first - y.first) + sqr(x.second - y.second));
}

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%lf%lf", &b[i].first, &b[i].second);
            par[i] = i; ranking[i] = 0;
        }

        int m = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                a[m++] = dii(dist(b[i],b[j]), ii(i,j));

        sort(a, a+m);
        double ans = 0;
        for(int i=0; i<m; i++)
            if(join(a[i].second.first, a[i].second.second)) ans += a[i].first;
        printf("%.2lf\n",ans);
        if(TC) printf("\n");
    }
    return 0;
}

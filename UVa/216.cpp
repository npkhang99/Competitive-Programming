#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 9;

int n, t = 0, b[N]={};
double c[N][N] = {}, ansCost;
ii a[N] = {};
vector<int> ansPath;

double dist(ii a, ii b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void optimize(double cost, vector<int> path){
    // printf("%.2lf %.2lf",cost,ansCost);
    if(cost < ansCost){
        ansCost = cost;
        ansPath = path;
    }
}

void DFS(int u, double cost, int cnt, vector<int> path){
    if(cnt == n){ optimize(cost, path); return; }
    b[u] = 1; path.push_back(0);
    for(int v=1; v<=n; v++)
        if(!b[v]) path[cnt] = v, DFS(v, cost + c[u][v], cnt+1, path);
    b[u] = 0;
}

int main(){
    while(scanf("%d",&n), n){
        for(int i=1; i<=n; i++) scanf("%d%d",&a[i].x,&a[i].y);

        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                c[i][j] = c[j][i] = dist(a[i],a[j]) + 16.0;
    
        ansCost = 10E36;

        for(int i=1; i<=n; i++)
            DFS(i, 0.0, 1, vector<int>(1,i));

        printf("**********************************************************\nNetwork #%d\n",++t);
        for(int i=1; i<ansPath.size(); i++)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",a[ansPath[i-1]].x, a[ansPath[i-1]].y, a[ansPath[i]].x,a[ansPath[i]].y,c[ansPath[i-1]][ansPath[i]]);
        printf("Number of feet of cable required is %.2lf.\n",ansCost);
    }
    return 0;
}

// Dijkstra's algorithm finding shortest path from S to T using heap (priority_queue)
// http://codeforces.com/problemset/problem/20/C
#include <iostream>   // cin cout
#include <stdio.h>    // freopen
#include <queue>      // priority_queue pop push top
#include <vector>     // vector
using namespace std;

typedef pair<int,int> ii;

const int N=100009;

int n, m, d[N]= {}, b[N]={}, tr[N]={};
vector<ii> a[N];

void readInput(){
    cin>> n>> m;
    for(int i=0; i<m; i++){
        int x,y,val; cin>> x>> y>> val;
        a[x].push_back(ii(y,val));
        a[y].push_back(ii(x,val));
    }
}

void trace(int u){
    if(u==0) return;
    trace(tr[u]);
    cout<< u<< " ";
}

void dijkstra(int s, int t){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i=1; i<=n; i++) d[i] = 10E8;
    d[s] = 0;
    pq.push(ii(0,s));
    while(!pq.empty() && pq.top().second != t){
        int u = pq.top().second, du = pq.top().first; pq.pop();
        b[u] = 1;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first, val = a[u][i].second;
            if(du + val < d[v]){
                d[v] = du+val;
                tr[v] = u;
                pq.push(ii(d[v],v));
            }
        }
    }
    // cout<< d[t]<< endl;
    if(!b[t] && pq.empty()) cout<< "-1\n";
    trace(t);
    cout<< '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    readInput();
    dijkstra(1,n);
    return 0;
}

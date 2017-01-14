#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000000000000

typedef pair<int,int> ii;

const int N = 100009;

int n, m, _c, d[N]={};
string s, t;
long long memo[N]={};
vector<ii> a[N];
map<string,int> f;

void dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii> > q;
    for(int i=1; i<=n; i++) d[i] = 10E8;
    q.push(ii(0,s)); d[s] = 0;
    while(!q.empty()){
        int u = q.top().second, du = q.top().first;
        q.pop();
        if(du > d[u]) continue;
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first, dv = a[u][i].second;
            if(du + dv < d[v]){
                d[v] = d[u] + dv;
                q.push(ii(d[v],v));
            }
        }
    }
}

long long tinh(int i){
    if(i == 2) return 1;
    if(memo[i] != -1) return memo[i];
    long long sl = 0;
    for(int j=0; j<a[i].size(); j++)
        if(d[i] > d[a[i][j].first]){
            sl += tinh(a[i][j].first);
            sl %= MOD;
        }
    return memo[i] = sl;
}

int find(string x){
    int y = f[x];
    if(!y) return f[x] = _c++;
    else return y;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Walk.inp","r",stdin);
    // freopen("Walk.out","w",stdout);
    while(cin>> n>> m>> s>> t){
        for(int i=1; i<=n; i++)
            a[i].clear();
        f.clear();
        f[s] = 1; f[t] = 2; _c = 3;
        for(int i=0; i<m; i++){
            string u, v;
            int x,y,val;
            cin>> v>> u>> val;
            x = find(u); y = find(v);
            a[x].push_back(ii(y,val));
            a[y].push_back(ii(x,val));
        }

        // for(map<string,int>::iterator it=f.begin(); it!=f.end(); it++)
        //     cerr<< it->first<< " -> "<< it->second<< endl;
        // cerr<< endl;

        dijkstra(2);
        // for(int i=1; i<=n; i++)
        //     cerr<< d[i]<< " ";
        // cerr<< endl;
        memset(memo, -1, sizeof memo);
        cout<< tinh(1)<< '\n';
    }
    return 0;
}

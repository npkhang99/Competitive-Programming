#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int n = 100;

int m, k, b[5], d[n] = {};
vector<ii> a[n];

int dijkstra(int s, int t){
    priority_queue<ii> q;
    for(int i=0; i<n; i++)
        d[i] = 1e9;
    d[s] = 0; q.push(ii(0,s));
    while(!q.empty()){
        int u = q.top().second,
            du = -q.top().first;
        q.pop();
        if(du > d[u]) continue;
        if(u == t) return max(0, du - 60);
        for(int i=0; i<a[u].size(); i++){
            int v = a[u][i].first,
                dv = a[u][i].second + 60;
            if(d[v] > du + dv){
                d[v] = du + dv;
                q.push(ii(-d[v],v));
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> m>> k){
        for(int i=0; i<n; i++)
            a[i].clear();
        for(int i=0; i<m; i++)
            cin>> b[i];
        cin.ignore();
        for(int i=0; i<m; i++){
            string st; getline(cin,st);
            stringstream ss(st);
            vector<int> temp;
            int x;
            while(ss>> x) temp.push_back(x);
            for(int j=0; j<temp.size(); j++)
                for(int k=j+1; k<temp.size(); k++){
                    int x = b[i] * (temp[k] - temp[j]);
                    a[temp[j]].push_back(ii(temp[k],x));
                    a[temp[k]].push_back(ii(temp[j],x));
                }
        }

        int ans = dijkstra(0,k);
        if(~ans) cout<< ans<< '\n';
        else cout<< "IMPOSSIBLE\n";
    }
    return 0;
}

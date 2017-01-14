#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
map<string,string> par;
map<string,int> size, ranking;

string root(string p){ return p==par[p]? p:root(par[p]); }

int join(string u, string v){
    u = root(u); v = root(v);
    if(u == v) return size[u];
    if(ranking[u] > ranking[v]){
        par[v] = u;
        return size[u] += size[v];
    }else{
        par[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
        return size[v] += size[u];
    }
}

void init(string x){
    if(par[x] == ""){
        par[x] = x;
        size[x] = 1;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int TC; cin>> TC;
    while(TC--){
        par.clear(); size.clear(); ranking.clear();
        cin>> n;
        for(int i=0; i<n; i++){
            string u,v; cin>> u>> v;
            init(u); init(v);
            cout<< join(u,v)<< '\n';
        }
    }
    return 0;
}

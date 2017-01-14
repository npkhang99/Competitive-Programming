#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;
typedef pair<int,string> is;
typedef pair<int,ss> iss;

const int N = 2009;

struct Edge{
    string v;
    string l1, l2;
}edge[N];

int m;
string s, t;
unordered_set<string> lang;
unordered_map<string, vector<is> > a;
unordered_map<string, int> d;

string dijkstra(){
    priority_queue<is> q;
    for(unordered_set<string>::iterator it = lang.begin(); it != lang.end(); it++)
        d[*it] = 1e9;
    d["$"] = 0; q.push(is(0,"$"));
    while(!q.empty()){
        int du = -q.top().first;
        string u = q.top().second;
        q.pop();
        if(du > d[u]) continue;
        if(u == "&") return to_string(du);
        for(int i=0; i<a[u].size(); i++){
            string v = a[u][i].second;
            int dv = a[u][i].first;
            if(d[v] > du + dv){
                d[v] = du + dv;
                q.push(is(-d[v], v));
            }
        }
    }
    return "impossivel";
}

bool shareCommonLang(int i, int j){
    return edge[i].l1 == edge[j].l1 || edge[i].l1 == edge[j].l2 || edge[i].l2 == edge[j].l1 || edge[i].l2 == edge[j].l2;
}

bool shareCommonLang(string s, int i){
    return s == edge[i].l1 || s == edge[i].l2;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> m, m){
        a.clear(); d.clear(); lang.clear();

        cin>> s>> t;
        lang.insert("$"); lang.insert("&");
        for(int i=0; i<m; i++){
            string x,y,z;
            cin>> x>> y>> z;
            lang.insert(z);
            edge[i].v = z;
            edge[i].l1 = x;
            edge[i].l2 = y;
        }

        for(int i=0; i<m; i++)
            for(int j=i+1; j<m; j++)
                if(i != j && shareCommonLang(i,j) && edge[i].v[0] != edge[j].v[0]){
                    a[edge[i].v].push_back(is(edge[j].v.size(), edge[j].v));
                    a[edge[j].v].push_back(is(edge[i].v.size(), edge[i].v));
                }
        for(int i=0; i<m; i++){
            if(shareCommonLang(s,i)) a["$"].push_back(is(edge[i].v.size(), edge[i].v));
            if(shareCommonLang(t,i)) a[edge[i].v].push_back(is(0, "&"));
        }

         cout<< dijkstra()<< '\n';
    }
    return 0;
}

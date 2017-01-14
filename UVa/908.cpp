#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fi first
#define se second
#define s se.fi
#define t se.se
#define val fi

#define all(a) a.begin(),a.end()

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N=1000009;

int n, parent[N]={}, m, x, y, v, cnt, k, T=0;
long long ans = 0;
vector<iii> edge, additional;

int root(int p){
    return p==parent[p]? p:root(parent[p]);
}

void join(int p, int q){
    parent[root(p)] = root(q);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> n){
        if(T++) cout<< '\n';
        edge.clear(); additional.clear();
        for(int i=1; i<=n; i++) parent[i] = i;
        for(int i=0; i<n-1; i++){
            cin>> x>> y>> v;
            edge.push_back(iii(v,ii(x,y)));
        }
        cin>> k;
        for(int i=0; i<k; i++){
            cin>> x>> y>> v;
            additional.push_back(iii(v,ii(x,y)));
        }
        cin>> m;
        for(int i=0; i<m; i++){
            cin>> x>> y>> v;
            edge.push_back(iii(v,ii(x,y)));
        }

        sort(all(edge));
        cnt = ans = 0;
        for(int i=0; i<edge.size(); i++)
            if(root(edge[i].s) != root(edge[i].t)){
                join(edge[i].s,edge[i].t);
                ans+=edge[i].val;
                cnt+=1;
                if(cnt==n-1) break;
            }

        cout<< ans<< '\n';

        for(int i=1; i<=n; i++) parent[i] = i;

        for(int i=0; i<additional.size(); i++) edge.push_back(additional[i]);
        sort(all(edge));
        cnt = ans = 0;
        for(int i=0; i<edge.size(); i++)
            if(root(edge[i].s) != root(edge[i].t)){
                join(edge[i].s,edge[i].t);
                ans+=edge[i].val;
                cnt+=1;
                if(cnt==n-1) break;
            }

        cout<< ans<< '\n';
    }
    return 0;
}

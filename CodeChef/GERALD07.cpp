#include <bits/stdc++.h>
using namespace std;

#define DEBUG1(X) { cerr << #X << " = " << (X) << endl; }
#define DEBUG2(X,c) { cerr << #X << " - " << (c) << " = " << (X) << endl; }
#define DEBUG3(X,l,r) { cerr << #X << "[" << l << ".." << r << "] = "; for(int i = l; i <= r; i++) cerr << X[i] << " "; cerr << endl; }

typedef pair<int,int> ii;

struct Query {
    int l, r, id;

    void read(int x){
        id = x;
        scanf("%d %d", &l, &r);
    }
};

struct Data {
    int idx, p, rank_change;
};

const int N = 200009;

int n, m, q, par[N]={}, ranking[N]={}, cnt, ans[N]={}, BASE;
ii edge[N]={};
vector<Query> query;
vector<Data> backup;

bool comp(const Query &a, const Query &b){
    if(a.l / BASE != b.l / BASE) return a.l < b.l;
    else return a.r < b.r;
}

int root(int p){
    return par[p] == p? p:root(par[p]);
}

void join(ii edge, bool snapshot){
    int u = root(edge.first),
        v = root(edge.second);
    if(u == v) return;
    if(ranking[u] <= ranking[v]){
        if(snapshot) backup.push_back({u,par[u],true});
        par[u] = v;
        if(ranking[u] == ranking[v]) ranking[v]++;
    }else{
        if(snapshot) backup.push_back({v,par[v],false});
        par[v] = u;
    }
    cnt--;
}

void init(){
    cnt = n;
    backup.clear();
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        ranking[i] = 0;
    }
}

void rollback(){
    for(int i = backup.size()-1; i >= 0; i--){
        cnt++;
        par[backup[i].idx] = backup[i].p;
        if(backup[i].rank_change) ranking[backup[i].p]--;
    }
    backup.clear();
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d %d", &n, &m, &q);
        for(int i = 1; i <= m; i++)
            scanf("%d %d", &edge[i].first, &edge[i].second);

        query.clear();
        for(int i = 0; i < q; i++){
            Query new_query;
            new_query.read(i);
            query.push_back(new_query);
        }

        BASE = sqrt(m);
        sort(query.begin(), query.end(), comp);

        init();

        for(Query q : query){
            if(q.l / BASE != q.r / BASE) continue;
            for(int i = q.l; i <= q.r; i++)
                join(edge[i],true);
            ans[q.id] = cnt;
            rollback();
        }

        int last_block = -1, l, r;
        for(Query q : query){
            if(q.l / BASE == q.r / BASE) continue;
            int block = q.l / BASE;
            if(last_block != block){
                init();
                l = (block + 1) * BASE;
                r = q.r;
                last_block = block;
                for(int i = l; i <= r; i++)
                    join(edge[i],false);
            }

            while(r < q.r) join(edge[++r],false);
            for(int i = l-1; i >= q.l; i--)
                join(edge[i],true);
            ans[q.id] = cnt;
            rollback();
        }

        for(int i = 0; i < q; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}

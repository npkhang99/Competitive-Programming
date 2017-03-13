#include <bits/stdc++.h>
using namespace std;

#define PRINT(a,s,e) { for(int i=s; i<=e; i++) cerr<< a[i]<< ' '; cerr<< endl; }

const int N = 200009;

int n, m, a[N]={};
long long it[4*N]={}, lazy[4*N]={};

vector<int> get_query(){
    string line; getline(cin, line);
    stringstream ss(line);
    vector<int> temp;
    int x;
    while(ss >> x) temp.push_back(x);
    return temp;
}

long long buildIT(int i, int l, int r){
    if(l == r) return it[i] = a[l];
    int mid = (l + r) >> 1;
    return it[i] = min(buildIT(i*2, l, mid), buildIT(i*2+1, mid+1, r));
}

long long update(int i, int l, int r, int L, int R, int v){
    if(lazy[i]){
        it[i] += lazy[i];
        if(l != r){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(r < L || R < l) return it[i];
    if(L <= l && r <= R){
        if(l != r){
            lazy[i*2] += v;
            lazy[i*2+1] += v;
        }
        return it[i] += v;
    }

    int mid = (l + r) >> 1;
    return it[i] = min(update(i*2, l, mid, L, R, v), update(i*2+1, mid+1, r, L, R, v));
}

long long rmq(int i, int l, int r, int L, int R){
    if(lazy[i]){
        it[i] += lazy[i];
        if(l != r){
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(r < L || R < l) return 1e18;
    if(L <= l && r <= R) return it[i];

    int mid = (l + r) >> 1;
    return min(rmq(i*2, l, mid, L, R), rmq(i*2+1, mid+1, r, L, R));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n;
    for(int i=0; i<n; i++)
        cin>> a[i];

    buildIT(1,0,n-1);

    cin>> m; cin.ignore();
    while(m--){
        vector<int> query = get_query();
        if(query.size() == 2){
            if(query[0] <= query[1]) cout<< rmq(1, 0, n-1, query[0], query[1])<< '\n';
            else cout<< min(rmq(1, 0, n-1, query[0], n-1), rmq(1, 0, n-1, 0, query[1]))<< '\n';
        }else{
            if(query[0] > query[1]){
                update(1, 0, n-1, query[0], n-1, query[2]);
                update(1, 0, n-1, 0, query[1], query[2]);
            }else update(1, 0, n-1, query[0], query[1], query[2]);
        }
    }
    return 0;
}

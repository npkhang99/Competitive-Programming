#include <bits/stdc++.h>
using namespace std;

const int N = 1024009;

int n, m, q, st[4*N]={}, lazy[4*N]={};
string a;

int build(int i, int l, int r){
    lazy[i] = 0;
    if(l == r) return st[i] = a[l] - 48;

    int mid = (l+r) >> 1;
    int p1 = build(i*2, l, mid),
        p2 = build(i*2+1, mid+1, r);
    return st[i] = p1 + p2;
}

int update(int i, int l, int r, int L, int R, int v, bool stop = false){
    if(lazy[i]){
        
        lazy[i] = 0;
    }

    if(stop) return st[i];

    if(r < L || R < l) return st[i];
    if(L <= l && r <= R){
        return st[i];
    }

    int mid = (l+r) >> 1;
    int p1 = update(2*i, l, mid, L, R, v),
        p2 = update(2*i+1, mid+1, r, L, R, v);
    return st[i] = p1 + p2;
}

int rsq(int i, int l, int r, int L, int R){
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return st[i];

    int mid = (l+r) >> 1;
    int p1 = rsq(2*i, l, mid, L, R),
        p2 = rsq(2*i+1, mid+1, r, L, R);
    return p1 + p2;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int TC; cin>> TC;
    for(int T=1; T<=TC; T++){
        cin>> m; a = "";
        for(int i=0; i<m; i++){
            int concat; string s;
            cin>> concat>> s;
            for(int j=0; j<concat; j++)
                a += s;
        }

        n = a.size();
        build(1,0,n-1);

        cin>> q; m = 0;
        char c; int x, y;
        cerr<< a<< " - "<< st[1]<< endl;
        cout<< "Case "<< T<< ":\n";
        for(int i=0; i<q; i++){
            cin>> c>> x>> y;
            if(c == 'F') update(1, 0, n-1, x, y, 1);
            else if(c == 'E') update(1, 0, n-1, x, y, 2);
            else if(c == 'I') update(1, 0, n-1, x, y, 3);
            else cout<< "Q"<< ++m<<": "<< rsq(1, 0, n-1, x, y)<< '\n';
            if(c != 'S') cerr<< st[1]<< endl;
        }
    }
    return 0;
}

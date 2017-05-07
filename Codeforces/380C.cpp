#include <bits/stdc++.h>
using namespace std;

struct Node {
    // opt   : optimal number of pairs
    // open  : number of ( left after delete all optimal brackets
    // close : number of ) left after delete all optimal brackets
    int opt, open, close;

    Node(int x, int y, int z){
        opt = x;
        open = y;
        close = z;
    }

    Node(){}
};

const int N = 1000009;

int n, q;
char st[N]={};
Node it[4*N];

Node operator + (const Node& left, const Node& right){
    Node result;
    int temp = min(left.open, right.close);

    result.opt = left.opt + right.opt + temp;
    result.open = left.open + right.open - temp;
    result.close = left.close + right.close - temp;

    return result;
}

Node build(int i, int l, int r){
    if(l == r){
        if(st[l] == '(') return it[i] = Node(0,1,0);
        else return it[i] = Node(0,0,1);
    }

    int mid = (l + r) >> 1;
    return it[i] = build(i*2, l, mid) + build(i*2+1, mid + 1, r);
}

Node query(int i, int l, int r, int L, int R){
    if(r < L || R < l) return Node(0,0,0);
    if(L <= l && r <= R) return it[i];

    int mid = (l + r) >> 1;
    return query(i*2, l, mid, L, R) + query(i*2+1, mid + 1, r, L, R);
}

int main(){
    scanf("%s%d", st+1, &q);
    n = strlen(st+1);

    build(1,1,n);

    while(q--){
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", query(1,1,n,l,r).opt*2);
    }
    return 0;
}

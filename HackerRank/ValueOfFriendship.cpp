// HackerRank - Week of Code 28 - The Value of Friendship
#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, m, par[N]={}, setRank[N]={};
long long setSize[N]={};

int root(int p){
    return p == par[p]? p:root(par[p]);
}

bool already_friend(int x, int y){
    return root(x) == root(y);
}

bool join(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(setRank[x] <= setRank[y]){
        par[x] = y;
        setSize[y] += setSize[x];
        if(setRank[x] == setRank[y]) setRank[y]++;
    }else{
        par[y] = x;
        setSize[x] += setSize[y];
    }
    return true;
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++){
            par[i] = i;
            setSize[i] = 1;
            setRank[i] = 0;
        }

        long long ans = 0, last = 0, t, t1, t2, old, later = 0;
        while(m--){
            int x, y; scanf("%d %d", &x, &y);
            if(!already_friend(x,y)){
                t1 = setSize[root(x)];
                t2 = setSize[root(y)];
                old = t1 * (t1-1) + t2 * (t2-1);
                join(x,y);
                t = setSize[root(x)];
                last += t * (t-1) - old;
                ans += last;
            }else later++;
        }
        printf("%lld\n", ans + last * later);
    }
    return 0;
}

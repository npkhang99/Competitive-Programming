#include <bits/stdc++.h>
using namespace std;

const int N = 609;

int n, m, k;
bool flag;
bitset<64> a[N]={};
bitset<N> e[N], d;

void sub1(bitset<64> c, bitset<64> u){
    if(c.count() + u.count() < k || flag) return;
    if(c.count() == k){
        for(int i=0; i<n; i++)
            if(c.test(i)) printf("%d ",i+1);
        flag = true;
        return;
    }

    int p = -1;
    for(int i=0; i<n; i++)
        if(u.test(i)){
            p = i;
            break;
        }

    sub1(c | (bitset<64>(1) << p), (u ^ (bitset<64>(1) << p)) & a[p]);
    sub1(c, u ^ (bitset<64>(1) << p));
}

void subtask1(){
    for(int i=0; i<n; i++)
        a[i].reset();
    for(int i=0; i<m; i++){
        int x,y; scanf("%d%d",&x,&y);
        x--; y--;
        a[x].set(y);
        a[y].set(x);
    }
    flag = false;
    bitset<64> u((1LL << n) - 1);
    // cerr<< u<< " ";
    sub1(0,u);
    if(!flag) printf("-1");
    // if(!flag) cerr<< -1<< endl;
    // else cerr<< k<< endl;
}

void subtask2(){
    for(int i=0; i<n; i++)
        e[i].reset();
    d.reset();
    for(int i=0; i<m; i++){
        int x, y; scanf("%d%d",&x,&y);
        x--; y--;
        e[x].set(y);
        e[y].set(x);
    }

    int cnt = n;
    for(int i=0; i<n; i++)
        if(!d.test(i)){
            for(int j=0; j<n; j++)
                if(i!=j && !d.test(j) && !e[i].test(j)){
                    d.set(i);
                    d.set(j);
                    cnt-=2;
                    break;
                }
        }

    cnt = 0;
    for(int i=0; i<n; i++){
        if(!d.test(i)){
            printf("%d ",i+1);
            if(++cnt == k) break;
        }
    }
    // cerr<< cnt<< endl;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Clique.inp","r",stdin);
    // freopen("Clique.out","w",stdout);
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d%d%d",&n,&m,&k);
        if(n <= 60) subtask1();
        else subtask2();
        printf("\n");
    }
    return 0;
}

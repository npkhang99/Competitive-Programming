#include <bits/stdc++.h>
using namespace std;

long long n, k, memo[69][69][2]={};
bitset<69> x, b;

long long gen(int i, int c, bool ok){
    if(c > x.count()) return 0;
    if(i == -1) return c == x.count() && ok;
    if(memo[i][c][ok] != -1) return memo[i][c][ok];
    int s;
    if(ok) s = 0;
    else s = x.test(i);
    long long temp = 0;
    for(int j=s; j<2; j++)
        temp += gen(i-1, c+j, ok || (j > x.test(i)));
    return memo[i][c][ok] = temp;
}

void trace(int i, int c, bool ok){
    if(i == -1) return;
    int s;
    if(ok) s = 0;
    else s = x.test(i);

    for(int j=s; j<2; j++){
        long long sl = gen(i-1, c+j, ok || (j > x.test(i)));
        if(sl < k) k -= sl;
        else{
            b.set(i,j);
            trace(i-1, c+j, ok || (j > x.test(i)));
            break;
        }
    }
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0);
    // freopen("Next.inp","r",stdin);
    // freopen("Next.out","w",stdout);
    int TC; scanf("%d",&TC);
    memset(memo,-1,sizeof memo);
    while(TC--){
        scanf("%lld%lld",&n,&k);
        b.reset(); x.reset();
        x = n;
        if(gen(60,0,false) < k){
            printf("-1\n");
            continue;
        }
        trace(60,0,false);
        long long ans = b.to_ullong();
        if(ans <= (long long)(1e15)){
            printf("%lld\n",ans);
            continue;
        }
        printf("-1\n");
    }
    return 0;
}

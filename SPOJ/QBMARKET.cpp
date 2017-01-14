#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 509;

int n, m, s, b[N]={};
ii a[N];
long long memo[N][100009];

long long buy(int p, int money){
    if(p == n || money < 0 || b[p] > a[p].second) return 0;
    if(money == 0) return 1;
    if(memo[p][money] != -1) return memo[p][money];
    b[p] += 1;
    long long cnt = buy(p, money - a[p].first) + buy(p+1, money);
    b[p] -= 1;
    return memo[p][money] = cnt;
}

int main(){
    scanf("%d %d",&s,&n);
    for(int i=0; i<n; i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    memset(memo, -1, sizeof memo);
    printf("%lld\n",buy(0,s));
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<=s; j++)
    //         printf("%5lld%c",memo[i][j], j==s? '\n':' ');
    return 0;
}

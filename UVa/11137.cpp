#include <cstdio>
#include <cstring>
using namespace std;

int n, d[21]={};
long long memo[21][10009]={};

long long ways(int p, int money){
    if(p == 21 || money < 0) return 0;
    if(money == 0) return 1;
    if(memo[p][money] != -1) return memo[p][money];
    return memo[p][money] = ways(p+1,money) + ways(p,money-d[p]);
}

int main(){
    for(int i=1; i<=21; i++)
        d[i-1] = i*i*i;
    memset(memo,-1,sizeof memo);
    while(~scanf("%d",&n))
        printf("%lld\n",ways(0,n));
    return 0;
}

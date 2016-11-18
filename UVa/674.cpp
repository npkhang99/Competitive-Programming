#include <cstdio>
#include <cstring>
using namespace std;

int n, c[] = {1,5,10,25,50};
long long memo[6][7500] = {};

long long btrack(int t, int n){
    if(n == 0) return 1;
    if(t > 4 || n < 0) return 0;
    return btrack(t+1, n) + btrack(t, n-c[t]);
}

int main(){
    memset(memo,-1,sizeof(memo));
    while(~scanf("%d",&n))
        printf("%lld\n",btrack(0,n));
    return 0;
}

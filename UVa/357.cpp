#include <cstdio>
#include <cstring>
using namespace std;

int n, c[] = {1,5,10,25,50};
long long memo[6][30009] = {};

long long btrack(int t, int n){
    if(n == 0) return 1;
    if(t > 4 || n < 0) return 0;
    if(memo[t][n] != -1) return memo[t][n];
    return memo[t][n] = btrack(t+1, n) + btrack(t, n-c[t]);
}

int main(){
    memset(memo,-1,sizeof(memo));
    while(~scanf("%d",&n)){
        long long ans = btrack(0,n);
        if(ans == 1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",btrack(0,n),n);
    }
    return 0;
}

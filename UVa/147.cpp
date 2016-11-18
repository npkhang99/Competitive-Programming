#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int d[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
long long memo[19][50009];
char st[9]={};

long long btrack(int c, int n){
    if(n == 0) return 1;
    if(n < 0 || c > 10) return 0;
    if(memo[c][n] != -1) return memo[c][n];
    return memo[c][n] = btrack(c, n-d[c]) + btrack(c+1, n);
}

int main(){
    memset(memo, -1, sizeof memo);
    while(scanf("%s",st), strcmp(st,"0.00")){
        int n = round(atof(st) * 100);
        printf("%6s%17lld\n",st,btrack(0,n));
    }
    return 0;
}

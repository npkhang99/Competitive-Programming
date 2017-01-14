#include <cstdio>
#include <cstring>
using namespace std;

const int N = 59;

int n, m, k;
long long memo[N][N][N][2]={};

long long count(int p, int c, int cnt, int last){
    if(c > m) return 0;
    if(p == n) return cnt == k;
    if(memo[p][c][cnt][last] != -1) return memo[p][c][cnt][last];
    return memo[p][c][cnt][last] = count(p+1, c+1, cnt, last) + count(p+1, 1, cnt+1, 1-last);
}

int main(){
    while(~scanf("%d%d%d",&n,&k,&m)){
        memset(memo, -1, sizeof memo);
        printf("%lld\n",count(1,1,1,1));
    }
    return 0;
}

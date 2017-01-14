#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1009;

int n, l, a[59], memo[N][N]={};

int min(int a, int b){
    return a<b? a:b;
}

int cut(int left, int right){
    if(right - left <= 1) return 0;
    if(memo[left][right] != -1) return memo[left][right];
    int cost = 10E8;
    for(int i=left+1; i<right; i++)
        cost = min(cost, cut(left,i) + cut(i,right) + a[right] - a[left]);
    return memo[left][right] = cost;
}

int main(){
    while(scanf("%d",&l), l){
        scanf("%d",&n);
        memset(memo, -1, sizeof memo);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        a[0] = 0; a[n+1] = l;
        printf("The minimum cutting is %d.\n",cut(0,n+1));
    }
    return 0;
}

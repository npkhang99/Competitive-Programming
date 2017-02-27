// HackerRank - University CodeSprint 2 - Game of Two Stacks
#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, m, limit;
long long a[N]={}, b[N]={};

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d %d %d", &n, &m, &limit);
        for(int i=1; i<=n; i++){
            scanf("%lld", &a[i]);
            a[i] += a[i-1];
        }
        for(int i=1; i<=m; i++){
            scanf("%lld", &b[i]);
            b[i] += b[i-1];
        }

        int ans = 0;
        for(int i=0; i<=n; i++)
            if(a[i] <= limit){
                int p = upper_bound(b, b+m+1, limit - a[i]) - b - 1;
                ans = max(ans, i + p);
            }

        printf("%d\n" ,ans);
    }
    return 0;
}

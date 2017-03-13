#include <bits/stdc++.h>
using namespace std;

const int N = 1009;

int n, m, p, a[N]={}, b[N]={};

int main(){
    scanf("%d %d %d", &p, &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<m; i++)
        scanf("%d", &b[i]);

    int ans = -1;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i] + b[j] <= p)
                ans = max(ans, a[i] + b[j]);

    printf("%d\n", ans);
    return 0;
}

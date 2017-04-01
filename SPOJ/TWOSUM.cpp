#include <bits/stdc++.h>
using namespace std;

const int N = 5009;

int n, a[N]={};

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int x; scanf("%d", &x);
        a[i] = a[i-1] + x;
    }

    int ans = 0;
    for(int i=n; i > 1 && !ans; i--)
        for(int j=1; j<=n-i+1 && !ans; j++){
            if((a[j+i-1] - a[j-1]) % 2) continue;
            if(binary_search(a+j, a+j+i-1, (a[j+i-1] - a[j-1])/2 + a[j-1])) ans = i;
        }

    printf("%d\n", ans);
    return 0;
}

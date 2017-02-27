#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, m, a[N]={};
bool removed[N]={};
char t[N]={}, p[N]={};

int main(){
    scanf("%s%s", t+1, p+1);
    n = strlen(t+1);
    m = strlen(p+1);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    int l = 0, r = n, ans = 0;
    while(l <= r){
        int mid = (l+r) >> 1;

        memset(removed, false, sizeof removed);
        for(int i=0; i<mid; i++)
            removed[a[i]] = true;

        bool found = false;
        for(int i=1, j=1; i<=n && j<=m; i++){
            if(removed[i]) continue;
            if(t[i] == p[j]) j++;
            if(j > m) found = true;
        }

        if(found){
            ans = mid;
            l = mid+1;
        }else r = mid - 1;
    }

    printf("%d\n", ans);
    return 0;
}

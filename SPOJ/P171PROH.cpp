#include <bits/stdc++.h>
using namespace std;

int n;
map<int,int> cnt, inPlace;

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x, y; scanf("%d %d", &x, &y);
        cnt[x] += 1; inPlace[x] += 1;
        if(x != y) cnt[y] += 1;
    }

    int ans = 1e9, mid = (1+n) >> 1;
    for(map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++)
        if(it->second >= mid){
            ans = min(ans, max(mid - inPlace[it->first], 0));
        }

    printf("%d\n", ans);
    return 0;
}

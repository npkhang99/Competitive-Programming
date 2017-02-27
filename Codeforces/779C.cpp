#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 200009;

int n, k, a[N]={}, b[N]={};
bool buy_first[N]={};
vector<ii> p1, p2;

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &b[i]);

    for(int i=0; i<n; i++){
        p1.push_back(ii(a[i] - b[i], i));
        p2.push_back(ii(b[i] - a[i], i));
    }

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    int ans = 0;
    for(int i=0; i<n; i++){
        if(p1[i].first > 0 && i >= k) break;
        ans += a[p1[i].second];
        buy_first[p1[i].second] = true;
    }

    for(int i=0; i<n; i++)
        if(!buy_first[i]) ans += b[i];

    printf("%d\n", ans);
    return 0;
}

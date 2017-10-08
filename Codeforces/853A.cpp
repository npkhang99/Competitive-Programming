#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 300009;

int n, k, a[N], ans[N]={};
set<int> available;
set<ii> wait;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        wait.insert(ii(-a[i],i+1));
    }

    for(int i = k+1; i <= k+n; i++)
        available.insert(i);

    long long cost = 0;
    while(!available.empty()){
        ii proc = *wait.begin(); wait.erase(wait.begin());
        set<int>::iterator new_time = available.lower_bound(proc.second);
        cost += -1LL * proc.first * (*new_time - proc.second);
        ans[proc.second-1] = *new_time;
        available.erase(new_time);
    }

    printf("%lld\n", cost);
    for(int i = 0; i < n; i++)
        printf("%d%c", ans[i], " \n"[i == n-1]);
    return 0;
}

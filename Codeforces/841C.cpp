#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 200009;

int n, a[N]={}, ans[N]={};
ii b[N]={};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] *= -1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i].first);
        b[i].second = i;
    }

    sort(a,a+n);
    sort(b,b+n);

    for(int i = 0; i < n; i++)
        ans[b[i].second] = -a[i];

    for(int i = 0; i < n; i++)
        printf("%d%c", ans[i], " \n"[i == n-1]);
    return 0;
}

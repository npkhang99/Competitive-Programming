// CodeChef
#include <bits/stdc++.h>
using namespace std;

#define LSOne(i) (i & (-i))

typedef pair<int,int> ii;

const int N = 100009;
const int BOUND = 1e9;

int n;
ii a[N]={};
unordered_map<int, long long> ft;

long long rsq(int a){
    long long s = 0;
    for(; a; s += ft[a], a -= LSOne(a));
    return s;
}

void update(int a){
    for(; a <= BOUND; ft[a]++, a += LSOne(a));
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &a[i].first, &a[i].second);
        a[i].first *= -1;
    }

    sort(a,a+n);

    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += rsq(a[i].second);
        update(a[i].second);
    }

    printf("%lld\n",ans);
    return 0;
}

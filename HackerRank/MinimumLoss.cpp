// HackerRank
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int N = 200009;

int n;
long long a[N]={};
set<long long> pay;

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lld",&a[i]);
    long long ans = 10E17;
    pay.insert(a[0]);
    for(int i=1; i<n; i++){
        set<long long>::iterator it = pay.upper_bound(a[i]);
        if(it != pay.end()) ans = min(ans, *it - a[i]);
        pay.insert(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

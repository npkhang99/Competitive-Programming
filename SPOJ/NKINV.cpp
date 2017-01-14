#include <cstdio>
using namespace std;

#define LSOne(i) (i & (-i))

const int N = 60009;

int n, a[N]={}, c[N]={}, ft[N]={};
long long ans = 0;

long long rsq(int a){
    long long sum = 0;
    for(; a; a -= LSOne(a)) sum += ft[a];
    return sum;
}

void update(int a){
    c[a]++;
    for(; a < N; a += LSOne(a)) ft[a]++;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[n-i-1]);
    for(int i=0; i<n; i++){
        ans += rsq(a[i]) - c[a[i]];
        update(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

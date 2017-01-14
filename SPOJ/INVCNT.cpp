#include <cstdio>
#include <cstring>
using namespace std;

#define LSOne(i) (i & (-i))

const int N = 200009;
const int BOUND = 1e7 + 9;

int n, a[N]={}, ft[BOUND]={};

long long rsq(int a){
    long long sum = 0;
    for(; a; a -= LSOne(a)) sum += ft[a];
    return sum;
}

void update(int a){
    for(; a < BOUND; a += LSOne(a)) ft[a]++;
}

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        memset(ft, 0, sizeof ft);
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[n-i-1]);

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += rsq(a[i]-1);
            update(a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

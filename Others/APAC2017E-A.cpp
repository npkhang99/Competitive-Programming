#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 109;

int T, a[N]={}, t=0;
long long x, y;
char st[N];

void small(){
    int ans = 0;
    for(int i=x - 1; i<y; i++)
        ans += (st[i % strlen(st)] == 'B');
    printf("Case #%d: %d\n",++t,ans);
}

void large(){
    int n = strlen(st);
    a[0] = (st[0] == 'B');
    for(int i=1; i<n; i++)
        a[i] = (st[i] == 'B') + a[i-1];

    long long ans = 0;
    for(long long i=x-1; i<y; i++){
        if(i % n == 0){
            ans += a[n-1]*((y-i) / n);
            i += n * ((y-i) / n);
            if(i < y) ans += (st[i % n] == 'B');
            continue;
        }
        ans += (st[i % n] == 'B');
    }
    printf("Case #%d: %lld\n",++t,ans);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s%lld%lld",st,&x,&y);
        // small();
        large();
    }
    return 0;
}

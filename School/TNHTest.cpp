#include <cstdio>
using namespace std;

long long a, b, c;

int main(){
    // freopen("TNHTest.inp","r",stdin);
    // freopen("TNHTest.out","w",stdout);
    scanf("%lld%lld%d",&a,&b,&c);
    long long ans = 1;
    for(int i=1; i<=b; i++) ans = (ans*a) % c;
    printf("%lld",ans);
    return 0;
}

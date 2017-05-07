#include <cstdio>
using namespace std;

const int N = 100009;

int n, m, a[N]={};
bool b[N]={};

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x; scanf("%d", &x);
        b[x] = 1;
    }

    a[0] = 0; a[1] = 1;
    for(int i=2; i<=n; i++)
        if(!b[i]) a[i] = (a[i-1] + a[i-2]) % 14062008;
    printf("%d\n", a[n]);
    return 0;
}

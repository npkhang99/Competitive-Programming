#include <stdio.h>
#include <math.h>
using namespace std;

int T, n, m;

int main(){
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        scanf("%d%d",&n,&m);
        n-=2, m-=2;
        int col = ceil(n/3.0), row = ceil(m/3.0);
        printf("%lld\n",(long long)(col*row));
    }
    return 0;
}

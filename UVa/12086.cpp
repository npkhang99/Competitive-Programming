#include <cstdio>
#include <cstring>
using namespace std;

#define LSOne(i) (i & (-i))

const int N = 200009;

int n, a[N]={}, ft[N]={}, T=0;

int rsq(int b){
    int sum = 0;
    for(; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}

int rsq(int a, int b){
    return rsq(b) - rsq(a-1);
}

void update(int a, int v){
    for(; a <= n; a += LSOne(a)) ft[a] += v;
}

int main(){
    while(scanf("%d",&n), n){
        if(T) printf("\n");
        printf("Case %d:\n",++T);
        memset(ft, 0, sizeof ft);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            update(i,a[i]);
        }
        char st[5];
        while(scanf(" %s",st), strcmp(st,"END")){
            int x, y; scanf("%d%d",&x,&y);
            if(!strcmp(st,"M")) printf("%d\n",rsq(x,y));
            else update(x, y - a[x]), a[x] = y;
        }
    }
    return 0;
}

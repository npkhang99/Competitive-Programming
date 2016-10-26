#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N=10009;

int T, n, q, k;
char st[N][30], un[] = "UNDETERMINED";
ii a[N];

char* find(){
    int cnt = 0, pos = 0;
    for(int i=0; i<n; i++){
        if(a[i].first <= k  && k <= a[i].second) cnt+=1, pos = i;
        if(cnt > 1) break;
    }
    return cnt==1? st[pos]:un;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%s%d%d",st[i],&a[i].first,&a[i].second);

        scanf("%d",&q);
        for(int i=0; i<q; i++){
            scanf("%d",&k);
            printf("%s\n",find());
        }
        if(T) printf("\n");
    }
    return 0;
}

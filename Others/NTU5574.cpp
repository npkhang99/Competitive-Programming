#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100009;

int n, m, a[N]={};
long long b[N]={};

int bsearch(int l, int r, long long need){
    int pos = r;
    while(l <= r){
        int mid = (l+r)/2;
        if(b[mid] >= need){
            pos = mid;
            r = mid-1;
        }else l = mid+1;
    }
    return pos;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        b[i] = a[i] + b[i-1];

    for(int query=0; query < m; query++){
        int x, y; scanf("%d%d",&x,&y);
        long long find = (b[y] - b[x-1]) / 2 + b[x-1];
        int i = bsearch(x, y, find);
        printf("%d\n",i);
        long long ans = b[y] - b[x-1];
        if(i-1 >= x) ans = min(ans, abs((b[y]-b[i-1]) - (b[i-1] - b[x-1])));
        if(i+1 <= y) ans = min(ans, abs((b[y]-b[i]) - (b[i] - b[x-1])));
        printf("%lld\n",ans);
    }
    return 0;
}

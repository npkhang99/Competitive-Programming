#include <cstdio>
#include <cmath>
using namespace std;

const int N=300009;

int n, m, a[N]={};

int search(int l, int r){
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2, cnt = 0;
        for(int i=0; i<m; i++) cnt += ceil(a[i]/double(mid));
        if(cnt <= n) ans = mid, r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int main(){
    // freopen("Marble.inp","r",stdin);
    // freopen("Marble.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) scanf("%d",&a[i]);
    printf("%d\n",search(1,1000000000));
    return 0;
}

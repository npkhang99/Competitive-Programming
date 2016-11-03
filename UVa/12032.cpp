#include <cstdio>
using namespace std;

const int N = 1000009;

int n, a[N]={}, T;

int jump(int k){
    int curr = 0, i = 0;
    while(i < n){
        if(a[i] - curr < k) curr = a[i++];
        else if(a[i] - curr == k) curr = a[i++], k-=1;
        else return 0;
    }
    return 1;
}

int main(){
    scanf("%d",&T);
    for(int t=0; t<T;){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        int l = 1, r = 10000000, ans = -1;
        while(l <= r){
            int mid = (l+r) / 2;
            if(jump(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        printf("Case %d: %d\n",++t,ans);
    }
    return 0;
}

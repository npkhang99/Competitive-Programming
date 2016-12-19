#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        int n; scanf("%d",&n);
        int ans = -1e9, l;
        scanf("%d",&l);
        for(int i=1; i<n; i++){
            int x; scanf("%d",&x);
            ans = max(ans, l - x);
            l = max(l,x);
        }
        printf("%d\n",ans);
    }
    return 0;
}

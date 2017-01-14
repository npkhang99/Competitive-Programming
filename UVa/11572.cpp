#include <cstdio>
#include <unordered_map>
using namespace std;

const int N = 1000009;

int n, a[N]={};
unordered_map<int,int> cnt;

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        cnt.clear();
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        int ans = 0, l = 0, r = 0;
        while(r < n){
            while(r < n && cnt[a[r-1]] < 2)
                cnt[a[r++]]++;
            ans = max(ans,r-l-1);
            while(l < n && cnt[a[r-1]] == 2)
                cnt[a[l++]]--;
        }
        ans = max(ans,r-l);
        printf("%d\n",ans);
    }
    return 0;
}

#include <cstdio>
using namespace std;

const int N = 1009;

int n, m, a[N]={};

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int l = 1, r = 10E8, ans = 0;
        while(l <= r){
            int mid = (l+r) / 2;
            int cnt = 1, temp = 0;
            for(int i=0; i<n; i++){
                while(temp + a[i] > mid){
                    cnt+=1;
                    if(cnt > m) break;
                    temp = 0;
                }
                temp += a[i];
            }
            if(cnt <= m){
                ans = mid;
                r = mid-1;
            }else l = mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

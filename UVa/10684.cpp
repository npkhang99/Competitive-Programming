#include <stdio.h>
using namespace std;

int n, t;

int main(){
    while(scanf("%d",&n), n){
        long long ans = 0, temp = 0;
        for(int i=0; i<n; i++){
            scanf("%d",&t);
            temp+=t;
            ans = temp>ans? temp:ans;
            if(temp<0) temp = 0;
        }
        if(ans) printf("The maximum winning streak is %lld.\n",ans);
        else printf("Losing streak.\n");
    }
    return 0;
}

#include <stdio.h>
using namespace std;

const int N=100009;

int T, n, a[N], b[N], cnt[N]={};

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]), cnt[i+1] = 0;
        for(int i=0; i<n; i++) scanf("%d",&b[i]);

        int l = 0, onlyOne = 0;
        for(int i=0; i<n; i++){
            if(i && !onlyOne) printf("%d-%d ",l+1,i), l=i;
            cnt[a[i]]+=1, cnt[b[i]]+=1;
            if(a[i]!=b[i] && cnt[a[i]]==2) onlyOne-=1;
            if(a[i]!=b[i] && cnt[b[i]]==2) onlyOne-=1;
            if(a[i]!=b[i] && cnt[a[i]]==1) onlyOne+=1;
            if(a[i]!=b[i] && cnt[b[i]]==1) onlyOne+=1;
        }
        printf("%d-%d\n",l+1,n);
    }
    return 0;
}

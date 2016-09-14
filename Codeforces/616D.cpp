#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

const int N=500009;

int n, k, a[N]={};
map<int,int> cnt;

int main(){
    scanf("%d%d\n",&n,&k);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    int l=0, r=0, ansl=0, ansr=0, diff=0;
    while(r<=n-1){
        if(++cnt[a[r]]==1) diff+=1;
        while(diff>k)
            if(--cnt[a[l++]]==0) diff-=1;
        if(ansr-ansl < r-l) ansr=r, ansl=l;
        r+=1;
    }
    printf("%d %d\n",ansl+1,ansr+1);
    return 0;
}

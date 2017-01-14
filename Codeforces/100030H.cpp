#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=100009;

int n, k, cnt[256]={};
char a[N]={};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d ",&k);
    scanf("%s",a); n = strlen(a);
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

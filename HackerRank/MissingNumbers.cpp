// HackerRank - Missing Numbers
#include <cstdio>
using namespace std;

const int N = 10009;

int n, cnt[N*2]={};

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        cnt[x]+=1;
    }

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        cnt[x]-=1;
    }

    for(int i=1; i<=N; i++)
        if(cnt[i]) printf("%d ",i);
    return 0;
}

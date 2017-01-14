#include <cstdio>
using namespace std;

const int N=100009;

int n, k, c, r, a[N]={};

int main(){
    while(scanf("%d",&k), k>0){
        scanf("%d",&n);
        for(int i=0; i<N; i++) a[i] = 0;
        for(int i=0; i<k; i++){
            int x; scanf("%d",&x);
            a[x] = 1;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int cnt=0;
            scanf("%d%d",&c,&r);
            for(int j=0; j<c; j++){
                int x; scanf("%d",&x);
                if(a[x]) cnt+=1;
            }
            if(cnt>=r) ans+=1;
        }
        if(ans==n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

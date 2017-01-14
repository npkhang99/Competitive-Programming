#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int T, n, a[N][N]={};

void fill(int x, int y, int k){
    for(int i=x; i<y; i++)
        for(int j=0; j<k; j++)
            a[i][j] = 1;
}

int main(){
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            int x,y,z; scanf("%d%d%d",&x,&y,&z);
            fill(x,y,z);
        }
        int cnt = 0;
        for(int i=0; i<105; i++)
            for(int j=0; j<105; j++)
                if(a[i][j]) cnt+=1;
        printf("%d\n",cnt);
    }
    return 0;
}

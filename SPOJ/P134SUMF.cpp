#include <stdio.h>
#include <math.h>
using namespace std;

const int N=1009;

int n, k, a[N]={};

int main(){
    scanf("%d%d",&n,&k);
    int cnt = 0;
    for(int i=2; i<=n; i++)
        if(!a[i])
            for(int j=1; j<=n/i; j++)
                if(!a[i*j]){
                    cnt += 1; a[i*j] = 1;
                    if(cnt == k){ printf("%d\n",i*j); return 0; }
                }
    return 0;
}

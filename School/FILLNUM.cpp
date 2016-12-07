#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;

int n, k, m, a[N]={}, b[N]={}, kNum;

int main(){
    // freopen("FILLNUM.inp","r",stdin);
    // freopen("FILLNUM.out","w",stdout);
    scanf("%d %d %d\n",&n,&m,&k);
    for(int i=0; i<m; i++){
        int x,y,val; scanf("%d %d %d\n",&x,&y,&val);
        b[x] = val; b[y+1] = -val;
    }
    kNum = 0; m = k;
    while(m>0){
        kNum+=1;
        m/=10;
    }
    int finalNum=0, x=0;
    for(int i=1; i<=n; i++){
        if(b[i]>0) s.push
        finalNum = finalNum*10 + x;
    }
    printf("%d %d\n",finalNum,finalNum%k);
    return 0;
}

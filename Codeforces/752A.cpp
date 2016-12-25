#include <bits/stdc++.h>
using namespace std;

const int N = 10009;

int n, m, k;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    int r = 1, c = 0, s = 0;
    for(int i=1; i<=n; i++)
        if(i*2*m >= k){
            c = i;
            s = m*(i-1)*2;
            break;
        }

    char side;
    if(k % 2 == 1) side = 'L', s+=1;
    else side = 'R', s+=2;


    for(int i=1; i<=m; i++, s+=2)
        if(s == k){
            // fprintf(stderr, "%d\n", s);
            r = i;
            break;
        }

    printf("%d %d %c\n",c,r,side);
    return 0;
}

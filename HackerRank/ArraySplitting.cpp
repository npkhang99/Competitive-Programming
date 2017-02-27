// HackerRank - Nikita and the Game
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=30009;

int n, a[N]={}, T;
long long L[N]={};

int btrack(int i, int j){
    if(i>=j || (L[j] - L[i-1]) % 2) return 0;
    int k = lower_bound(L+i,L+j+1, (L[i-1] + L[j]) / 2) - L;
    if(L[k] != (L[i-1] + L[j]) / 2) return 0;
    int temp = 0;
    temp = max(temp, max(btrack(i,k) + 1, btrack(k+1,j) + 1));
    return temp;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]), L[i] = L[i-1] + a[i];
        printf("%d\n",btrack(1,n));
    }
    return 0;
}

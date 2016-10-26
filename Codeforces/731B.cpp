#include <cstdio>
using namespace std;

const int N=200009;

int n, a[N]={};

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<n; i++){
        if(a[i] < 0 || (a[i]%2 == 1 && i+1 == n)){ printf("NO\n"); return 0; }
        if(a[i]%2 == 0) continue;
        a[i+1] -= 1;
    }
    printf("YES\n");
    return 0;
}

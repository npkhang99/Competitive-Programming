#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N=300009;

int n, a[N];

int main(){
    // freopen("KNJI.inp","r",stdin);
    // freopen("KNJI.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d\n",&a[i]);
    int last = n;
    for(int i=n-1; i>=0; i--)
        if(a[i]==last) last-=1;
    printf("%d\n",last);
    return 0;
}

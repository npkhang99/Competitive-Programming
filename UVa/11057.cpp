#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10009;

int n, a[N]={}, s;

int main(){
    while(~scanf("%d",&n)){
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&s);

        sort(a,a+n);

        int total = 0, p1 = 0, p2 = 0;
        for(int i=1; i<n; i++){
            int need = s - a[i];
            if(a[0] > need) break;
            if(a[i-1] < need) continue;
            int j = lower_bound(a,a+i,need) - a;
            if(a[j] > need) j--;
            if(a[i] + a[j] > total){
                total = a[i] + a[j];
                p1 = a[j]; p2 = a[i];
            }else if(a[i] == a[j] == total && a[i] - a[j] < p2 - p1) p1 = a[j], p2 = a[i];
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",p1,p2);
    }
    return 0;
}

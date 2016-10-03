#include <bits/stdc++.h>
using namespace std;

const int N=100009;

int n, a[N]={}, b[N]={}, sum=0;

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    sort(a,a+n);
    for(int i=0; i<n; i++) b[i] = sum/n;
    int left = sum-(sum/n)*n;
    for(int i=n-1; i>=n-left; i--) b[i]+=1;

    int ans = 0;
    for(int i=0; i<n; i++)
        ans += abs(a[i]-b[i]);
    printf("%d\n",ans/2);
    return 0;
}

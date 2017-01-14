#include <stdio.h>
#include <deque>
using namespace std;

const int N=1000009;

int n, a[N], k;
deque<int> deQ;

int main(){
    freopen("Minimum.inp","r",stdin);
    freopen("Minimum.out","w",stdout);
    scanf("%d %d\n",&n,&k);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    
    int i=0;
    for(; i<k; i++){
        while(!deQ.empty() && a[i]<=a[deQ.back()]) deQ.pop_back();
        deQ.push_back(i);
    }
    for(; i<n; i++){
        printf("%d\n",a[deQ.front()]);
        while(!deQ.empty() && deQ.front()<=i-k) deQ.pop_front();
        while(!deQ.empty() && a[i]<=a[deQ.back()]) deQ.pop_back();
        deQ.push_back(i);
    }
    printf("%d\n",a[deQ.front()]);
    return 0;
}

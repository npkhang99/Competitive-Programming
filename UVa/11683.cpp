#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

const int N=10009;

int n, m, a[N], T;

int main(){
    while(scanf("%d",&m), m){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);

        stack<int> s;
        long long ans = m-a[0];
        s.push(a[0]);
        for(int i=1; i<n; i++){
            if(a[i]>=a[i-1] && a[i+1]>=a[i]) continue;
            if(a[i]<a[i-1]) ans+=a[i-1]-a[i];
            while(!s.empty() && a[i]>=s.top()) s.pop();
            if(s.empty() || s.top()>a[i]){
                s.push(a[i]);
                continue;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

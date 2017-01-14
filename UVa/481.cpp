#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int N=1000009;

int n = -1, m = 0, a[N]={}, L[N]={}, b[N]={};

int main(){
    while(scanf("%d",&a[++n])!=EOF){}
    for(int i=0; i<n; i++){
        L[i] = lower_bound(b,b+m,a[i]) - b;
        m = max(m,L[i]+1);
        b[L[i]] = a[i];
    }

    printf("%d\n-\n",m--);
    stack<int> ans;
    for(int i=n-1; i>=0; i--)
        if(L[i] == m) ans.push(a[i]), m-=1;
    while(!ans.empty()) printf("%d\n",ans.top()), ans.pop();
    return 0;
}

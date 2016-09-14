#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

const int N=500009;

int n, m, a[N], r[N], l[N];
long long ans;

long long find(){
    stack<int> s;
    s.push(0);
    for(int i=1; i<n; i++){
        while(!s.empty() && a[i]<a[s.top()]){
            r[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        r[s.top()] = n-s.top();
        s.pop();
    }
    
    while(!s.empty()) s.pop();
    s.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && a[i]<a[s.top()]){
            l[s.top()] = s.top()-i-1;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        l[s.top()] = s.top();
        s.pop();
    }
    
    long long t = 0;
    for(int i=0; i<n; i++) t = max(t,(long long)((long long)(l[i]+r[i])*(long long)a[i]));
    return t;
}

int main(){
    // freopen("RECT.inp","r",stdin);
    // freopen("RECT.out","w",stdout);
    scanf("%d%d\n",&n,&m);
    swap(n,m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    ans = find();
    for(int i=0; i<n; i++) a[i] = m-a[i];
    ans = max(ans,find());
    printf("%I64d\n",ans);
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

const int N=1009;

int n, m, a[N][N]={}, l[N], r[N];;
string st;

long long calc(int base){
    stack<int> s;
    s.push(0);
    for(int i=1; i<m; i++){
        while(!s.empty() && a[base][i]<a[base][s.top()]){
            r[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        r[s.top()] = m-s.top();
        s.pop();
    }
    
    s.push(m-1);
    for(int i=m-2; i>=0; i--){
        while(!s.empty() && a[base][i]<a[base][s.top()]){
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
    for(int i=0; i<m; i++) t = max(t,(long long)(l[i]+r[i])*(long long)a[base][i]);
    return t;
}

int main(){
    // freopen("MAXRECT.inp","r",stdin);
    // freopen("MAXRECT.out","w",stdout);
    cin>> n>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch; cin>> ch;
            if(ch=='B') a[i][j]=0;
            else a[i][j]=1;
            if(i>0 && a[i][j]==1) a[i][j]=a[i-1][j]+1;
        }
        
    }
    long long ans = 0;
    for(int i=0; i<n; i++) ans = max(ans,calc(i));
    printf("%I64d\n",ans);
    return 0;
}
// PTIT
#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> ci;

const int N = 500009;

int n, k, b[N]={};
char a[N]={};

int main(){
    scanf("%d%d%s",&n,&k,a);
    priority_queue<ci, vector<ci>, greater<ci> > q;
    int p = 0;
    while(k && p < n){
        if(q.empty() || q.top().first >= a[p]){
            q.push(ci(a[p],-p)); p++;
            continue;
        }
        while(k && !q.empty() && a[p] > q.top().first){
            b[-q.top().second] = 1;
            q.pop(); k--;
        }
        q.push(ci(a[p],-p)); p++;
    }
    while(k--){
        b[-q.top().second] = 1;
        q.pop();
    }

    for(int i=0; i<n; i++)
        if(!b[i]) printf("%c",a[i]);
    printf("\n");
    return 0;
}

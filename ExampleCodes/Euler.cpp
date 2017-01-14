#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

const int N=1009;

int n, m, a[N][N]={};
stack<int> s;

int main(){
    cin>> n>> m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>> x>> y;
        a[x][y]=a[y][x]=1;
    }
    s.push(1);
    while(!s.empty()) {
        int u = s.top(), foundLoop=1;
        for(int v=1; v<=n; v++){
            if(a[u][v]){
                a[u][v]=a[v][u]=0;
                foundLoop=0;
                s.push(v);
                break;
            }
        }
        if(foundLoop){
            printf("%d ",u);
            s.pop();
        }
    }
    return 0;
}

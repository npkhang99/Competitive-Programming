#include <iostream>    // cin
#include <stdio.h>     // printf freopen
#include <stdlib.h>    // exit
#include <vector>      // vector
using namespace std;

const int N=1009;

int n, m, a[N][N]={}, b[N]={};

void printHamilton(int u){
    vector<int> ans;
    ans.push_back(1);
    do{
        ans.push_back(u);
        u=b[u];
    }while(u!=-1);
    for(int i=0; i<ans.size(); i++) printf("%d ",ans[ans.size()-i-1]);
    printf("\n");
    exit(0);
}

void DFS(int u, int vertexNum){
    for(int v=1; v<=n; v++)
        if(vertexNum==n && v==1) printHamilton(u);
        else if(vertexNum<n && a[u][v] && !b[v]){
            b[v]=u;
            DFS(v,vertexNum+1);
        }
}

int main(){
    cin>> n>> m;
    for(int i=0; i<m; i++){
        int x,y; cin>> x>> y;
        a[x][y]=a[y][x]=1;
    }
    b[1]=-1;
    DFS(1,1);
    printf("-1\n");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define left(i) (2*i)
#define right(i) (2*i+1)

int a[(1 << 20)+9][29]={};
bool status[(1 << 20)+9]={};

void traverse(int node, int d, int ball){
    if(d > 20) return;
    if(status[node] == false){
        status[node] = true;
        a[ball][d] = node;
        traverse(left(node), d+1, ball);
        return;
    }
    status[node] = false;
    a[ball][d] = node;
    traverse(right(node), d+1, ball);
}

int main(){
    for(int i=1; i <= 524288; i++) traverse(1,1,i);
    int TC; scanf("%d",&TC);
    while(TC--){
        int n, m; scanf("%d%d",&n,&m);
        printf("%d\n",a[m][n]);
    }
    return 0;
}

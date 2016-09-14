#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define val first
#define u second.first
#define v second.second

typedef pair<int,pair<int,int> > iii;

const int N=109;

int n, m, T, b[N*N]={}, root[N]={};
iii a[N*N];

int findRoot(int p){
    return root[p]==p? p:(root[p] = findRoot(root[p]));
}

void joint(int p, int q){
    root[findRoot(p)] = findRoot(q);
}

void init(){
    for(int i=0; i<=max(n,m); i++){
        if(i<=n) root[i] = i;
        b[i] = 0;
    }
}

void resetRoot(){
    for(int i=1; i<=n; i++) root[i] = i;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        for(int i=0; i<m; i++){
            int x,y,val;
            scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].val);
        }
        sort(a,a+m);
        int ans1 = 0, ans2 = 10E8;
        for(int i=0; i<m; i++)
            if(findRoot(a[i].u) != findRoot(a[i].v)){
                joint(a[i].u,a[i].v);
                ans1+=a[i].val;
                b[i] = 1;
            }

        for(int j=0; j<m; j++){
            if(!b[j]) continue;
            int t=0, find=0;
            resetRoot();
            for(int i=0; i<m; i++)
                if(i!=j && findRoot(a[i].u) != findRoot(a[i].v)){
                    joint(a[i].u,a[i].v);
                    t+=a[i].val;
                    find+=1;
                }
            if(find==n-1) ans2 = min(ans2,t);
        }
        printf("%d %d\n",min(ans1,ans2),max(ans1,ans2));
    }
    return 0;
}

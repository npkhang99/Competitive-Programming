#include <bits/stdc++.h>
using namespace std;

#define x first.first
#define y first.second

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int N=100009;

int n, m, k;
iii a[N];

bool isCorner(int x, int y){
    return (x==0 && y==0) || (x==0 && y==m) || (x==n && y ==0) || (x==n && y==m);
}

int main(){
    // scanf("%d%d%d",&n,&m,&k);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(int i=0; i<k; i++){
            int X, Y; scanf("%d%d",&X,&Y);
            a[i] = iii(ii(X,Y),i);
        }

    }
    return 0;
}

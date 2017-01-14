#include <stdio.h>
#include <set>
using namespace std;

const int N=29;

int n, m, a[N][N]={};

int check(int j){
    set<int> s;
    for(int i=0; i<n; i++)
        if(s.find(a[i][j]) == s.end()) s.insert(a[i][j]);
    return s.size() < 3;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) scanf("%d",&a[i][j]);

    int flag = 0, cnt = 0;
    for(int i=0; i<m; i++)
        if(!check(i)) cnt+=1;
    if(flag){ printf("NO\n"); return 0; }
    for(int i=0; i<m; i++){

    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N=30009;

int T, n, m, a[N]={}, b[N]={};
multiset<int> s;
multiset<int>::iterator it;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        for(int i=1; i<=m; i++) scanf("%d",&b[i]);
        
        s.clear();
        int first = 1;
        for(int i=1,j=1; i<=m; i++){
            while(b[i] >= j){
                s.insert(a[j]);
                if(!first && a[j] < *it) it--;
                j+=1;
            }
            if(first) it = s.begin(), first = 0;
            else it++;
            printf("%d\n",*it);
        }
        if(T) printf("\n");
    }
    return 0;
}

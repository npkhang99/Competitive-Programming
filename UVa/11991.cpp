#include <cstdio>
#include <vector>
using namespace std;

const int N = 1000009;

int n, m, b[N]={}, c = 0;
vector<int> a[N];

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            if(b[x] != c){
                b[x] = c;
                a[x].clear();
            }
            a[x].push_back(i+1);
        }

        for(int i=0; i<m; i++){
            int k, v; scanf("%d%d",&k,&v);
            if(k > a[v].size()) printf("0\n");
            else printf("%d\n",a[v][k-1]);
        }
        c++;
    }
    return 0;
}

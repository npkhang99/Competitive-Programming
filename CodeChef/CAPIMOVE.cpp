// CodeChef
#include <bits/stdc++.h>
using namespace std;

const int N = 50009;

int n;
pair<int,int> p[N];
vector<int> a[N];

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        for(int i=1; i<=n; i++)
            a[i].clear();

        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&p[i].first);
            a[i].push_back(p[i].first);
            p[i].second = i;
        }

        for(int i=1; i<n; i++){
            int x,y; scanf("%d%d",&x,&y);
            a[x].push_back(p[y].first);
            a[y].push_back(p[x].first);
        }

        sort(p+1, p+n+1);
        reverse(p+1, p+n+1);
        for(int i=1; i<=n; i++)
            sort(a[i].begin(), a[i].end());

        for(int i=1; i<=n; i++)
            if(a[i].size() < n){
                for(int j=1; j<=n; j++)
                    if(!binary_search(a[i].begin(), a[i].end(), p[j].first)){
                        printf("%d ", p[j].second);
                        break;
                    }
            }else printf("0 ");
        printf("\n");
    }
    return 0;
}

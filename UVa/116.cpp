#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define all(a) a.begin(),a.end()

const int N = 109;
const int d[] = {-1,0,1};

int n, m, a[19][N], dp[19][N]={};
vector<int> tr[19][N];

int mod(int x){
    if(x == -1) return n-1;
    else if(x == n) return 0;
    else return x;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&a[i][j]),
                tr[i][j].clear(), dp[i][j] = 10E8;

        for(int i=0; i<n; i++){
            dp[i][0] = a[i][0];
            tr[i][0].push_back(i);
        }

        for(int j=0; j<m-1; j++)
            for(int i=0; i<n; i++){
                for(int k=0; k<3; k++){
                    if(dp[mod(i+d[k])][j+1] > dp[i][j] + a[mod(i+d[k])][j+1]){
                        dp[mod(i+d[k])][j+1] = dp[i][j] + a[mod(i+d[k])][j+1];
                        tr[mod(i+d[k])][j+1] = tr[i][j];
                        tr[mod(i+d[k])][j+1].push_back(mod(i+d[k]));
                        continue;
                    }
                    if(dp[mod(i+d[k])][j+1] == dp[i][j] + a[mod(i+d[k])][j+1]){
                        vector<int> temp = tr[i][j];
                        temp.push_back(mod(i+d[k]));
                        if(lexicographical_compare(all(temp),all(tr[mod(i+d[k])][j+1])))
                            tr[mod(i+d[k])][j+1] = temp;
                    }
                }
            }
            
        int ans = 10E8;
        vector<int> trace;
        for(int i=0; i<n; i++)
            if(ans > dp[i][m-1] || (ans == dp[i][m-1] && lexicographical_compare(all(tr[i][m-1]),all(trace)))){
                ans = dp[i][m-1];
                trace = tr[i][m-1];
            }
        for(int i=0; i<m; i++)
            printf("%d%c", trace[i]+1, i==m-1? '\n':' ');
        printf("%d\n",ans);
    }
    return 0;
}

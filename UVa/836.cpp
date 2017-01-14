#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=29;

int T, n, L[N][N]={};

int main(){
    scanf("%d",&T);
    while(T--){
        char a[N][N]={};
        scanf("%s",a[0]); n = strlen(a[0]);
        for(int i=1; i<n; i++) scanf("%s",a[i]);

        for(int i=0; i<n; i++)
            for(int j=1; j<n; j++)
                if(a[i][j] != a[i][j-1]) L[i][j] = L[i][j-1] + 1;
                else L[i][j] = L[i][j-1];

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++) printf("%d ",L[i][j]);
        //     printf("\n");
        // }

        int ans = 0;
        for(int l = 0; l < n; l++)
            for(int r = l; r < n; r++){
                int top = 0;
                for(int i = 0; i < n; i++){
                    if((a[i][l] != '1' || a[i][r] != '1') || (a[i][l] == '1' && L[i][l] != L[i][r])){ top = i+1; continue; }
                    if(a[top][l] != a[i][l] || a[top][r] != a[i][r]) top = i;
                    ans = max(ans, (i-top+1)*(r-l+1));
                }
            }
        printf("%d\n",ans);
        if(T) printf("\n");
    }
    return 0;
}

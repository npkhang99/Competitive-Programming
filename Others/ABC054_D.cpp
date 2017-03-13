// AtCoder Beginner Contest 054 - D. Mixing Experiments
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

struct Package {
    int a, b, c;

    Package(int x, int y, int z){
        a = x; b = y; c = z;
    }
};

int n, ma, mb, dp[509][509];
vector<Package> packs;

int main(){
    scanf("%d%d%d", &n ,&ma, &mb);
    for(int i=0; i<n; i++){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        packs.push_back(Package(x,y,z));
    }

    memset(dp, 63, sizeof dp);
    int INF = dp[0][0]; dp[0][0] = 0;
    for(Package pack : packs) {
        for(int i=400; ~i; i--)
            for(int j=400; ~j; j--)
                if(dp[i][j] == INF) continue;
                else dp[i + pack.a][j + pack.b] = min(dp[i + pack.a][j + pack.b], dp[i][j] + pack.c);
    }

    int ans = INF;
    for(int i=ma, j=mb; i<=500 && j<=500; i+=ma,j+=mb){
        ans = min(ans, dp[i][j]);
    }

    printf("%d\n", ans == INF? -1:ans);
    return 0;
}

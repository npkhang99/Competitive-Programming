#include <bits/stdc++.h>
using namespace std;

const int N = 509;

int n, q;
long long black[N][N]={}, white[N][N]={};

long long get_black(int i, int j, int u, int v){
    return black[u][v] - black[i-1][v] - black[u][j-1] + black[i-1][j-1];
}

long long get_white(int i, int j, int u, int v){
    return white[u][v] - white[i-1][v] - white[u][j-1] + white[i-1][j-1];
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            int x; scanf("%d", &x);
            if(i % 2 == j % 2) white[i][j] = x;
            else black[i][j] = x;
            white[i][j] += white[i][j-1] + white[i-1][j] - white[i-1][j-1];
            black[i][j] += black[i][j-1] + black[i-1][j] - black[i-1][j-1];
        }

    scanf("%d", &q);
    while(q--){
        int x, y, z, t; scanf("%d %d %d %d", &x, &y, &z, &t);
        // cerr<< get_black(x,y,z,t)<< " "<< get_white(x,y,z,t)<< endl;
        printf("%lld\n", abs(get_black(x,y,z,t) - get_white(x,y,z,t)));
    }
    return 0;
}

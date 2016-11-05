#include <iostream>
#include <string>
using namespace std;

const int N=1009;

int n, m, k, dp[N][N][15][2]={};
string s, t;

int max(int a, int b){ return a>b? a:b; }

int main(){
    cin>> n>> m>> k>> s>> t;
    s = "#" + s; t = "$"+t;
    /* dp[i][j][x][t]: maximum total length of each indivitual string in the collection
     *    - i: first i characters of string S
     *    - j: first j characters of string T
     *    - x: divided into x substrings
     *    - t -> 1: force to choose element S[i] and T[j] (only if S[i] == T[j])
     *           0: optional
     * => dp[n][m][k][0] is the answer
     */
    dp[0][0][0][0] =  0;
    dp[0][0][0][1] = -1;
    for(int x=1; x<=k; x++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i] != t[j]){
                    dp[i][j][x][0] = max(dp[i-1][j][x][0], dp[i][j-1][x][0]);
                    dp[i][j][x][1] = -1;
                    continue;
                }
                dp[i][j][x][1] = max(dp[i-1][j-1][x][1], dp[i-1][j-1][x-1][0]) + 1;
                dp[i][j][x][0] = max(dp[i][j][x][1], max(dp[i-1][j][x][0], dp[i][j-1][x][0]));
            }
        }
    }

    cout<< dp[n][m][k][0]<< endl;
    return 0;
}

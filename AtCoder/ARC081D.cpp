#include <bits/stdc++.h>
using namespace std;

const int N = 59;

int n, memo[9][N][9][9]={};
string s[3];

int dp(int i, int j, int l1, int l2){
    if(j == s[0].size()) return 1;

    if(~memo[i][j][l1][l2]) return memo[i][j][l1][l2];
    if(i == 0 && s[0][j] == s[1][j]) return memo[i][j][l1][l2] = dp(1,j,l1,l2);

    int temp = 0;
    for(int c = 1; c <= 3; c++){
        if(c != l1 && c != l2){
            temp = (temp + dp((i + 1) % 2, j + (i == 1), l2 * (s[0][j] != s[1][j]), c)) % 1000000007;
            // fprintf(stderr, "%d %d %d %d %d - %d\n", i, j, l1, l2, c, temp);
        }
    }
    return memo[i][j][l1][l2] = temp;
}

int main(){
    cin >> n >> s[0] >> s[1];
    for(int i = 1; i < s[0].size(); i++){
        if(s[0][i] == s[0][i-1]) s[0].erase(s[0].begin()+i);
        if(s[1][i] == s[1][i-1]) s[1].erase(s[1].begin()+i);
    }
    memset(memo, -1, sizeof memo);
    cout << dp(0,0,0,0) << endl;
    return 0;
}

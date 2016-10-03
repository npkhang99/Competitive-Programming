#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N=209;

int n, m, dp[N][N]={};
string s1, s2;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("ChChung.inp","r",stdin);
    // freopen("ChChung.out","w",stdout);
    cin>> s1>> s2;
    swap(s1,s2);
    n = s1.size(); m = s2.size();

    for(int i=n-1; i>=0; i--)
        for(int j=m-1; j>=0; j--)
            if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1]+1;
            else dp[i][j] = max(dp[i][j+1],dp[i+1][j]);

    int next_i = 0, next_j = 0, len = dp[0][0]+1;
    string ans="";
    while(--len){
        int num;
        for(num=9; num>=0; num--){
            int x=-1, y=-1;
            for(int i=next_i; i<n; i++)
                if(s1[i] == num+48){ x = i; break; }
            for(int j=next_j; j<m; j++)
                if(s2[j] == num+48){ y = j; break; }
            
            if(!num && len==dp[0][0]) break;
            if(x!=-1 && y!=-1 && dp[x][y] == len){
                next_i = x+1;
                next_j = y+1;
                break;
            }
        }
        if(num || ans.size()) ans += char(num+48);
    }
    cout<< ans<< '\n';
    return 0;
}

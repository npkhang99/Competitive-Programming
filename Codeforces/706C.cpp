#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int N=100009;

int n, m, c[N];
long long dp[N][3]={};
string a[N];

string reverse(string x){
    string st="";
    for(int i=x.size()-1; i>=0; i--)
        st+=x[i];
    return st;
}

int comp(string a, string b){
    for(int i=0; i<min(a.size(),b.size()); i++)
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return 0;
    return a.size()>=b.size();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> c[i];
        dp[i][0] = dp[i][1] = 10E17;
    }
    for(int i=0; i<n; i++) cin>> a[i];
    dp[0][0] = 0; dp[0][1] = c[0];
    for(int i=1; i<n; i++){
        if(comp(a[i],a[i-1])) dp[i][0] = min(dp[i][0],dp[i-1][0]);
        if(comp(a[i],reverse(a[i-1]))) dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if(comp(reverse(a[i]),a[i-1])) dp[i][1] = min(dp[i][1],dp[i-1][0]+c[i]);
        if(comp(reverse(a[i]),reverse(a[i-1]))) dp[i][1] = min(dp[i][1],dp[i-1][1]+c[i]);
    }
    if(dp[n-1][0]==10E17 && dp[n-1][1]==10E17) printf("-1\n");
    else printf("%lld\n",min(dp[n-1][0],dp[n-1][1]));
    return 0;
}

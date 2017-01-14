#include <bits/stdc++.h>
using namespace std;

int n, k, cnt[256]={};
string st;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n>> k>> st;
    int l=-1, r=-1, ans = 0;
    while(r<n){
        while(r<n && (cnt['a']<=k || cnt['b']<=k)) cnt[st[++r]]+=1;
        ans = max(ans,r-l-1);
        while(l<n && cnt['a']>k && cnt['b']>k) cnt[st[++l]]-=1;
    }
    ans = max(ans,r-l-1);
    cout<< ans<< '\n';
    return 0;
}

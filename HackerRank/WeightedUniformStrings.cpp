// HackerRank - CodeSprint 9 - Weighted Uniform Strings
#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int TC, n;
char st[N];
vector<int> a;

int main(){
    cin>> st>> TC;
    n = strlen(st);
    int l = 0, r = 0;
    while(r < n){
        while(r < n-1 && st[l] == st[r+1]){
            a.push_back((r - l + 1) * (st[l] - 'a' + 1));
            r++;
        }
        a.push_back((r - l + 1) * (st[l] - 'a' + 1));
        l = ++r;
    }
    
    sort(a.begin(), a.end());
    while(TC--){
        int x; cin>> x;
        if(binary_search(a.begin(), a.end(), x)) cout<< "Yes\n";
        else cout<< "No\n";
    }
    return 0;
}

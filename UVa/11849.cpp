#include <bits/stdc++.h>
using namespace std;

int n, m, x, ans = 0;
set<int> a;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> n>> m, n && m){
        ans = 0; a.clear();
        for(int i=0; i<n; i++){
            cin>> x; a.insert(x);
        }
        for(int i=0; i<m; i++){
            cin>> x;
            if(a.find(x)!=a.end()) ans+=1;
        }
        cout<< ans<< '\n';
    }
    return 0;
}

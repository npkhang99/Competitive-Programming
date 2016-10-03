#include <bits/stdc++.h>
using namespace std;

int n, m;
string st;

bool check(int n){
    int size = st.size()/n;
    for(int i=0; i<size; i++){
        for(int j=i+size; j<st.size(); j+=size)
            if(st[i]!=st[j]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> st, st!="."){
        int n = st.size();
        for(m=n; m>=2; m--){
            if(n%m) continue;
            if(check(m)) break;
        }
        cout<< m<< '\n';
    }
    return 0;
}

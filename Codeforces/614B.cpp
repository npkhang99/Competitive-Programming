#include <bits/stdc++.h>
using namespace std;

const int N=100009;

int n, zeros = 0;
string st, ans = "1";

bool isBeautiful(){
    if(st[0]!='1') return false;
    for(int i=1; i<st.size(); i++)
        if(st[i]!='0') return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> st;
        if(st == "0"){
            cout<< "0\n";
            return 0;
        }
        if(isBeautiful()) zeros += st.size()-1;
        else ans = st;
    }
    cout<< ans;
    for(int i=0; i<zeros; i++) cout<< '0';
    cout<< '\n';
    return 0;
}

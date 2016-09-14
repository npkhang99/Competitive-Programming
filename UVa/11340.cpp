#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int T, n;
string st;
map<char,int> a;

int main(){
    ios::sync_with_stdio(false);
    cin>> T;
    while(T--){
        a.clear();
        cin>> n;
        for(int i=0; i<n; i++){
            char ch; int money;
            cin>> ch>> money;
            a[ch] = money;
        }
        long long ans=0;
        cin>> n; cin.ignore();
        for(int i=0; i<n; i++){
            getline(cin,st);
            for(int j=0; j<st.length(); j++) ans+=a[st[j]];
        }
        printf("%.02lf$\n",ans/100.0);
    }
    return 0;
}

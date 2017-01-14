#include <iostream>
#include <string>
#include <list>
using namespace std;

int T;
string st;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> T;
    while(T--){
        cin>> st;
        list<char> ans;
        list<char>::iterator it = ans.begin();
        for(int i=0; i<st.size(); i++){
            if(st[i]=='>' && it!=ans.end()) it++;
            if(st[i]=='<' && it!=and.begin()) it--;
            if(st[i]=='-' && it.size() && it)
        }
    }
    return 0;
}

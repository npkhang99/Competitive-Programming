#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int n, ans=0;
string st;

int type(char c){
    if(c == 'L' || c == 'R') return 0;
    if(c == 'D' || c == 'U') return 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n>> st;

    vector<char> currPath;
    for(int i=0; i<n; i++){
        if(!currPath.size()){
            currPath.push_back(st[i]);
        }

        else if(currPath.size() == 1){
            if(currPath[0] != st[i] && type(currPath[0]) != type(st[i])) currPath.push_back(st[i]);
            else if(currPath[0] != st[i] && type(currPath[0]) == type(st[i])){
                currPath.clear(); currPath.push_back(st[i]);
                ans++;
            }
        }

        else if(st[i] != currPath[0] && st[i] != currPath[1]){
            currPath.clear(); currPath.push_back(st[i]);
            ans++;
        }
    }

    cout<< ++ans<< '\n';
    return 0;
}

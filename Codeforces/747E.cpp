#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

int n, depth=0, maxDepth=0;
string st;
vector<string> tree[N];
stack<int> s;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>> st; n = st.size();
    for(int i=0; i<n; i++){
        string temp = "";
        while(i < n && st[i] != ',') temp += st[i++]; i++;
        // cerr<< temp<< " "<< depth<< endl;
        tree[depth].push_back(temp);
        maxDepth = max(maxDepth, depth);

        string child = "";
        while(i < n && st[i] != ',') child += st[i++];
        int c = stoi(child);
        if(c) s.push(c), depth++;
        else while(!s.empty()){
            int c = s.top()-1;
            s.pop();
            if(c){
                s.push(c);
                break;
            }else depth--;
        }
    }
    cout<< maxDepth+1<< '\n';
    for(int i=0; i<=maxDepth; i++){
        for(int j=0; j<tree[i].size(); j++)
            cout<< tree[i][j]<< " ";
        cout<< '\n';
    }
    return 0;
}

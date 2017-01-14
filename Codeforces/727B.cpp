#include <bits/stdc++.h>
using namespace std;

string st;
double ans = 0.0, curr = 0.0;
int flag = 0;

int main(){
    cin>> st;
    for(int i=0; i<st.size(); i++){
        if('a' <= st[i] && st[i] <= 'z'){ ans += curr; curr = 0.0; continue; }
        if(st[i] == '.'){
            if(i+3 < st.size() && '0' <= st[i+3] && st[i+3] <= '9'){
                curr = curr*1000 +  st[i+1]*100 + st[i+2]*10 + st[i+3] - 48*111;
                i += 3;
                continue;
            }
            curr += (st[i+1]*10 + st[i+2] - 48*11) / 100.0;
            i += 2;
            continue;
        }
        curr = curr*10 + st[i] - 48;
    }

    ans+=curr;
    string s = to_string(ans); s.erase(s.end()-4,s.end());
    int n = s.size();
    stack<char> S;
    if(s[n-1] != '0' || s[n-2] != '0') S.push(s[n-1]), S.push(s[n-2]), S.push('.');
    for(int i=n-4, j=1; i>=0; i--, j++){
        S.push(s[i]);
        if(j%3==0 && i) S.push('.');
    }
    while(!S.empty()) cout<< S.top(), S.pop();
    cout<< endl;
    return 0;
}

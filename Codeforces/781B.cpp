#include <bits/stdc++.h>
using namespace std;

const int N = 1009;

int n;
string a[N], b[N], ans[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n;
    for(int i=1; i<=n; i++){
        string s, t; cin>> s>> t;
        a[i] = s.substr(0,3);
        b[i] = s.substr(0,2) + t[0];
    }

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(a[i] == a[j]){
                ans[i] = b[i];
                ans[j] = b[j];
            }

    set<string> used;
    for(int i=1; i<=n; i++)
        if(ans[i] != "") used.insert(ans[i]);

    while(true){
        bool found = false;

        for(int i=1; i<=n; i++){
            if(ans[i] == ""){
                if(used.count(a[i]) || used.count(b[i])){
                    if(used.count(a[i])) ans[i] = b[i];
                    else ans[i] = a[i];
                    used.insert(ans[i]);
                    found = true;
                }
            }
        }

        if(!found){
            for(int i=1; i<=n; i++){
                if(ans[i] == ""){
                    found = true;
                    ans[i] = a[i];
                    used.insert(ans[i]);
                }
            }
        }

        if(!found) break;
    }

    int have_answer = true;
    for(int i=1; i<=n && have_answer; i++){
        for(int j=i+1; j<=n && have_answer; j++)
            if(ans[i] == ans[j]) have_answer = false;
    }

    cout<< (have_answer? "YES":"NO")<< '\n';
    if(have_answer){
        for(int i=1; i<=n; i++)
            cout<< ans[i]<< '\n';
    }
    return 0;
}

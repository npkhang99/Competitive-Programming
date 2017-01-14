#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string n, m;

int main(){
    // freopen("Collide.inp","r",stdin);
    // freopen("Collide.out","w",stdout);
    cin>> n>> m;
    string ans1="0", ans2="0";
    while(n.size() < m.size()) n = '$' + n;
    while(n.size() > m.size()) m = '$' + m;
    for(int i=0; i<n.size(); i++){
        if(n[i] > m[i]) ans1 = ans1 + n[i];
        else if(n[i] < m[i]) ans2 = ans2 + m[i];
        else ans1 = ans1 + n[i], ans2 = ans2 + m[i];
    }
    while(ans1.size() > 1 && ans1[0] == '0') ans1.erase(ans1.begin());
    while(ans2.size() > 1 && ans2[0] == '0') ans2.erase(ans2.begin());
    cout<< ans1<< endl<< ans2<< endl;
    return 0;
}

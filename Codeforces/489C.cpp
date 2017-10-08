#include <bits/stdc++.h>
using namespace std;

int n, s;
string s1, s2;

bool run1(int i, int x, string st = ""){
    if(x > s) return false;
    // cerr << i << " " << st <<  " " << x << endl;
    if(i == n){
        if(x == s) s1 = st;
        return (x == s);
    }
    for(int j = (i == 0 && n > 1); j < 10; j++){
        if(x + 9 * (n - i) < s) continue;
        if(run1(i+1, x+j, st + to_string(j))) return true;
    }
    return false;
}

bool run2(int i, int x, string st = ""){
    if(x > s) return false;
    // cerr << i << " " << st <<  " " << x << endl;
    if(i == n){
        if(x == s) s2 = st;
        return (x == s);
    }
    for(int j = 9; j >= (i == 0 && n > 1); j--){
        if(x + 9 * (n - i) < s) continue;
        if(run2(i+1, x+j, st + to_string(j))) return true;
    }
    return false;
}

int main(){
    cin >> n >> s;
    s1 = s2 = "-1";
    run1(0,0); run2(0,0);
    cout << s1 << " " << s2 << endl;
    return 0;
}

// https://cses.fi/problemset/task/1069
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string st;
    cin >> st;
    int ans = 1;
    int cnt = 1;
    for (int i = 1; i < (int) st.length(); i++) {
        if (st[i - 1] == st[i]) {
            cnt += 1;
        }
        else {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}

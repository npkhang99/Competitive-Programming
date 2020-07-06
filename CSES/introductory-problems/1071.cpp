#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int level = max(x, y) - 1;
        int pos = min(x, y);
        long long answer = 1ll * level * level + 1;
        if (x == y) {
            cout << answer + (level + 1) << endl;
        }
        else {
            answer += (level + 1) * (1 - level % 2);
            answer += pos;
            cout << answer << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long level = max(x, y);

        long long lower = (level - 1) * (level - 1) + 1;
        long long upper = level * level;
        long long mid = (upper + lower) / 2;

        if (level % 2 == 0) {
            if (x > y) {
                cout << upper - y + 1 << endl;
            }
            else if (x < y) {
                cout << lower + x - 1 << endl;
            }
            else {
                cout << mid << endl;
            }
        }
        else {
            if (x > y) {
                cout << lower + y - 1 << endl;
            }
            else if (x < y) {
                cout << upper - x + 1 << endl;
            }
            else {
                cout << mid << endl;
            }
        }
    }
    return 0;
}

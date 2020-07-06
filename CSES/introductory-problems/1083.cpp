// https://cses.fi/problemset/task/1083
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum << endl;
    return 0;
}

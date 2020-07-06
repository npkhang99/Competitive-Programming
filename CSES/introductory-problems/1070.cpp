#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 2; i <= n; i += 2) {
        a.push_back(i);
    }
    for (int i = 1; i <= n; i += 2) {
        a.push_back(i);
    }

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (abs(a[i - 1] - a[i]) == 1) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n -1];
        }
    }
    return 0;
}

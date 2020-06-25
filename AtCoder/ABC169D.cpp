#include <bits/stdc++.h>
using namespace std;

bitset<1000009> bs;
vector<int> primes;

void sieve(int upper_bound) {
    bs.reset();
    bs.set(0);
    bs.set(1);

    for (int i = 2; i < upper_bound; i++) {
        if (bs.test(i)) {
            continue;
        }

        primes.push_back(i);
        for (long long j = 1ll * i * i; j < upper_bound; j += i) {
            bs.set(j);
        }
    }
}

int main() {
    sieve(1000009);
    long long n;
    cin >> n;
    
    vector<int> p;
    int i = 0;
    while (i < (int) primes.size() && n > 1) {
        int cnt = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            cnt++;
        }

        if (cnt) {
            p.push_back(cnt);
        }
        i++;
    }

    if (n > 1) {
        n /= n;
        p.push_back(1);
    }

    int ans = 0;
    for (int i : p) {
        int t = 0;
        for (int j = 1; t + j <= i; j++) {
            t += j;
            ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}

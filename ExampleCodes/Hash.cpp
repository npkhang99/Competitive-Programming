// Hash - A String Matching Algorithm
// Find all the occurrences of a substring P (of length m) in a (long) string T (of length n)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000111;
const ll MOD = 1e9 + 7;

int n, m;
ll POW[N]={}, hashT[N]={};
string T, P;

ll getHashT(int i, int j) {
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    // Input 
    cin >> T >> P;

    // Initialize
    n = T.size(); m = P.size();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;

    // Precalculate 26^i
    // You can change 26 to any number you preffer
    for(int i = 1; i <= n; i++)
        POW[i] = (POW[i - 1] * 26) % MOD;

    // Calculate hash value of T[1..i]
    for(int i = 1; i <= n; i++)
        hashT[i] = (hashT[i - 1] * 26 + T[i] - 'a') % MOD;

    // Calculate hash value of P
    ll hashP=0;
    for(int i = 1; i <= m; i++)
        hashP = (hashP * 26 + P[i] - 'a') % MOD;

    // Finding substrings of T equal to string P
    for(int i = 1; i <= n - m + 1; i++)
        if (hashP==getHashT(i, i + m - 1))
            cout<< i<< " ";
    cout<< endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
const int MOD = 1000000007;

int n, c, a[N]={}, ans;
vector<int> prime, factor;
bitset<3> b;
bitset<30000009> xxx;

void sieve(int upperBound = (int)1e6){
    for(int i=2; i<=upperBound; i++)
        if(!xxx[i]){
            prime.push_back(i);
            for(int j=i+i; j<=upperBound; j+=i) xxx[j] = 1;
        }
}

vector<int> primeFactors(int x){
    vector<int> factors;
    int p = 0;
    while(x > 1){
        while(x % prime[p] == 0){
            x /= prime[p];
            if(factors.empty() || factors.back() != prime[p]) factors.push_back(prime[p]);
        }
        p++;
    }
    return factors;
}

long long poww(long long a, int n){
    if(n == 0) return 1;
    if(n == 1) return a;
    long long x = poww(a, n / 2);
    if(n % 2 == 1) return (((x*x) % MOD)*a) % MOD;
    else return (x*x) % MOD;
}

int calc(){
    // cerr<< b<< endl;
    vector<int> x;
    for(int i=0; i<n; i++)
        if(b[i]) x.push_back(a[i]);
    // cerr<< endl;
    if(x.empty()) return 0;
    int gcd = x[0];
    for(int i=1; i<x.size(); i++){
        gcd = __gcd(gcd, x[i]);
        if(gcd == 1) return 1;
    }
    return poww(c, primeFactors(gcd).size());
}

void btrack(int i){
    if(i == n){
        ans = (ans + calc()) % MOD;
        return;
    }

    for(int j=0; j<2; j++){
        b[i] = j;
        btrack(i+1);
    }
}

int main(){
    sieve();
    scanf("%d%d",&n,&c);
    if(c == 1){
        ans = (poww(2, n) - 1);
        printf("%d\n", ans);
        return 0;
    }
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    btrack(0);
    printf("%d\n", ans);
    return 0;
}

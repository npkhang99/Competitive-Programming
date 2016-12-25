#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[N]={};
vector<int> prime, factor[N*10];
bitset<1000009> b;

void sieve(){
    int upperBound = (int)1e6 + 1;
    prime.push_back(1);
    for(int i=2; i<=upperBound; i++)
        if(!b[i]){
            prime.push_back(i);
            for(int j=i+i; j<=upperBound; j+=i) b[j] = 1;
        }
}

vector<int> primeFactors(int x){
    vector<int> factors;
    int p = 1;
    while(x > 1){
        while(x % prime[p] == 0){
            x /= prime[p];
            if(factors.empty() || factors.back() != prime[p]) factors.push_back(prime[p]);
        }
        p++;
    }
    return factors;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // freopen("LCM.inp","r",stdin);
    // freopen("LCM.out","w",stdout);
    sieve();
    int TC; cin>> TC;
    while(TC--){
        cin>> n;
        for(int i=0; i<n; i++)
            cin>> a[i];

        int ans = 0;
        b.reset();
        for(int i=0; i<n; i++){
            vector<int> factors = primeFactors(a[i]);
            int flag = 0;
            for(int j=0; j<factors.size(); j++)
                if(b[factors[j]]){
                    flag = 1;
                    break;
                }
            if(flag || (a[i]==1 && b[1])) continue;
            b[a[i]] = 1;
            for(int j=0; j<factors.size(); j++)
                b[factors[j]] = 1;
            ans += 1;
        }

        cout<< (ans>1? ans:-1)<< '\n';
    }
    return 0;
}

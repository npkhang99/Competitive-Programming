#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

int n;
vector<int> sieve(N,1);

void generate_sieve(){
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i <= sqrt(N) + 1; i++)
        if(sieve[i] == 1){
            for(int j = i*i; j < N; j+=i)
                sieve[j] = 0;
        }
}

int main(){
    generate_sieve();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x; scanf("%d", &x);
        if(x > 0 && (sieve[x-1] == 1 || sieve[x] == 1 || sieve[x+1] == 1)) printf("1\n");
        else printf("0\n");
    }
    return 0;
}

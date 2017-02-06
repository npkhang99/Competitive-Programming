#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> divisor;

int main(){
    scanf("%lld %lld", &n, &k);
    for(int i=1; i<=round(sqrt(n)); i++)
        if(n % i == 0) divisor.push_back(i);

    for(int i=divisor.size()-1; i>=0; i--)
        if(n / divisor[i] != divisor[i]) divisor.push_back(n / divisor[i]);

    printf("%lld\n", k > divisor.size()? -1:divisor[k-1]);
    return 0;
}

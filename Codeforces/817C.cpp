#include <bits/stdc++.h>
using namespace std;

#define log(n,base) (log(n)/log(base))

long long n, s;
int x, a[20]={};

void sep_digits(long long n){
    x = (int)log(n,10) + 1;
    for(int i = 1; i <= x; i++){
        a[i] = n % 10;
        n /= 10;
    }
}

long long pow(long long a, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return a;
    long long m = pow(a, exp/2);
    if(exp % 2 == 1) return m * m * a;
    else return m * m;
}

long long suy_bien(int p, bool kt){
    if(kt == false) return pow(10LL,p);
    long long result = 1;
    for(int i = p; i > 0; i--)
        result += a[i] * pow(10LL,i-1);
    return result;
}

bool no_chance(int p, long long u){
    // long long t = 0;
    for(int i = p; i > 0; i--)
        u += 9 * (pow(10LL,i-1) - 1);
    return u < s;
}

long long tinh(int i, bool kt, long long u, bool kt2){
    if(kt == true) return suy_bien(i, kt2);
    
    if(kt == false && kt2 == false && no_chance(i,u)) return 0;
    if(i == 1) return 0;

    int f;
    long long dem = 0, temp = 0;
    if(kt2 == true) f = a[i];
    else f = 9;
    for(long long j=f; ~j; j--){
        long long v = u + j * (pow(10LL,i-1) - 1LL);
        temp = tinh(i-1, v >= s, v, kt2 == true && j == f);
        // if(temp == 0) break;
        dem += temp;
    }
    return dem;
}

int main(){
    while(~scanf("%lld %lld", &n, &s)){
        sep_digits(n);
        printf("%lld\n", tinh(x,false,0,true));
    }
    return 0;
}

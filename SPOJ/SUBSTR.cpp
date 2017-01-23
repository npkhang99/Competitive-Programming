#include <cstdio>
#include <cstring>
using namespace std;

#define ll long long

const int N = 1000009;

const int MOD = 1e9 + 7;

int n, m, b[N]={};
char T[N]={}, P[N]={};
ll P_hash[N]={}, T_hash[N]={}, M[N]={};

//------------ KMP -------------
void preKMP(){
    int i = 0, j = -1; b[0] = -1;
    while(i < m){
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void KMP(){
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if(j == m){
            printf("%d ", i - j + 1);
            j = b[j];
        }
    }
}

void useKMP(){
    preKMP();
    KMP();
}

//----------- HASH -------------
void build_hash(char a[], int n, ll H[]){
    for(int i=0; i<n; i++)
        H[i] = ((i? H[i-1]:0) * M[1] + a[i]) % MOD;
}

ll get_hash(ll H[], int l, int r){
    return (H[r] - (l? H[l-1]:0) * M[r-l+1] + 1ll * MOD * MOD) % MOD;
}

void useHash(){
    M[0] = 1; M[1] = 2817;
    for(int i=2; i<n; i++)
        M[i] = (M[1] * M[i-1]) % MOD;

    build_hash(T, n, T_hash);
    build_hash(P, m, P_hash);
    for(int i=0; i < n-m+1; i++)
        if(get_hash(T_hash, i, i+m-1) == P_hash[m-1]) printf("%d ", i+1);
}

int main(){
    scanf("%s %s", T, P);
    n = strlen(T);
    m = strlen(P);
    // useKMP();
    useHash();
    printf("\n");
    return 0;
}

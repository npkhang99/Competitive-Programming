#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000009;

int n, m, b[N]={};
char T[N]={}, P[N]={};

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

int main(){
    scanf("%s %s", T, P);
    n = strlen(T);
    m = strlen(P);
    preKMP();
    KMP();
    printf("\n");
    return 0;
}

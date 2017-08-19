#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, m, b[N]={};
char T[N], P[N] = "happiness";
vector<int> found;

void kmpPreprocess(){
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch(){
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if (j == m) {
            found.push_back(i-j);
            j = b[j];
        }
    }
}

int main(){
    scanf("%s", T);
    n = strlen(T);
    m = strlen(P);
    kmpPreprocess();
    kmpSearch();
    if(found.size() == 0){
        printf("YES\n1 2\n");
    }else if(found.size() == 1){
        printf("YES\n%d %d\n", found[0]+1, found[0]+2);
    }else if(found.size() == 2){
        printf("YES\n%d %d\n", found[0]+1, found[1]+2);
    }else printf("NO\n");
    return 0;
}

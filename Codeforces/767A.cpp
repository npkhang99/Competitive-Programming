#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[N]={};
bool have[N]={};

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(int i=0, j=n; i<n; i++){
        have[a[i]] = true;
        while(have[j]) printf("%d ", j--);
        printf("\n");
    }
    return 0;
}

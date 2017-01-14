// HackerRank - University CodeSprint - Kindergarten Adventures
#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[N]={}, b[N]={};

int mod(int x){
    return (x + n) % n;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(int i=0; i<n; i++){
        int l = mod(i - a[i] + 1), r = mod(i + 1);
        if(a[i] / n > 1) continue;
        b[l] -= 1; b[r] += 1;
    }

    int ans = 0, c = b[0], x = 0;
    for(int i=0; i<n; i++)
        c += b[i];
    x = c;
    for(int i=1; i<n; i++){
        x += b[i];
        if(x > c){
            ans = i;
            c = x;
        }
    }
    printf("%d\n", ans+1);
    return 0;
}

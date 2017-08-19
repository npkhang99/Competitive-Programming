#include <bits/stdc++.h>
using namespace std;

const double pi = 4 * atan(1);
const int N = 100009;

int n, a[N]={}, r = 0, r2;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        r += a[i];
        if(i > 0) a[i] += a[i-1];
    }
    r2 = r / 3;

    if(r2 * 3 != r){
        printf("0\n");
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(binary_search(a, a+n, a[i] + r2) && binary_search(a, a+n, a[i] + 2*r2) && a[i] + 3*r2 - r == a[i]) cnt++;
    printf("%d\n", cnt);
    return 0;
}

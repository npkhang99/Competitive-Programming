#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

bool fulfill(int x){
    int temp = 0;
    for(int i=1; i<=int(round(sqrt(x))); i++){
        if(x % i) continue;
        temp += i + x / i;
        if(i*i == x) temp -= i;
    }
    return temp > 2*x;
}

int main(){
    int l, r; scanf("%d%d", &l, &r);
    int ans = 0;
    for(int i=l; i<=r; i++)
        if(fulfill(i)) ans++;
    printf("%d\n", ans);
    return 0;
}

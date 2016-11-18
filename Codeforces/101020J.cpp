#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        printf("%s\n", __gcd(a,b)==1? "GOOD":"NOT GOOD");
    }
    return 0;
}

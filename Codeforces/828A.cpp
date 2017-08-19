#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, a, b, c = 0, ans = 0;

int main(){
    scanf("%d %d %d", &n, &a, &b);
    while(n--){
        int x; scanf("%d", &x);
        if(x == 1){
            if(a != 0) a--;
            else if(b != 0) b--, c++;
            else if(c != 0) c--;
            else ans++;
        }else{
            if(b != 0) b--;
            else ans += 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}

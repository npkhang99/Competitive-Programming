#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000009;

int n;
long long x_left = 0, y_left = 0;
char st[N]={}, x, y;

int main(){
    scanf("%[^\n] %c%c", st, &x, &y);
    n = strlen(st);

    if(x == st[0]) x_left = 1;
    if(y == st[0]) y_left = 1;

    for(int i=1; i<n; i++){
        if(x == st[i]) x_left += 1;
        if(y == st[i]) y_left += 1;
    }

    long long ans = 0;
    for(int i=0; i<n; i++){
        if(y == st[i]) y_left -= 1;
        if(x == st[i]){
            ans += y_left;
            x_left -= 1;
        }
        if(!x_left || !y_left) break;
    }
    printf("%lld\n",ans);
    return 0;
}

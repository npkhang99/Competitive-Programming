#include <cstdio>
#include <cstring>
using namespace std;

const int N=100009;

char st[N];

int main(){
    // freopen("Poker.inp","r",stdin);
    // freopen("Poker.out","w",stdout);
    while(~scanf("%s",st)){
        int flag = 0, cnt[256]={}, b[256][20]={};
        for(int i=0; i<strlen(st);){
            int set = st[i], power = st[i+1]*10 + st[i+2] - 48*11;
            if(b[set][power]){ printf("-1\n"); flag = 1; break; }
            cnt[set] += 1; b[set][power] = 1;
            i+=3;
        }
        if(!flag) printf("%d %d %d %d\n",13-cnt['P'],13-cnt['K'],13-cnt['H'],13-cnt['T']);
    }
    return 0;
}

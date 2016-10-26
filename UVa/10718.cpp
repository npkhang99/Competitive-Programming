#include <cstdio>
using namespace std;

unsigned int n, m, l, r;

bool inrange(long long x){
    return l <= x && x <= r;
}

int main(){
    while(~scanf("%u%u%u",&n,&l,&r)){
        int first;
        for(int i=32; i>=0; i--)
            if((r >> i) & 1LL){ first = i; break; }

        m = l;
        for(int i=first; i>=0; i--){
            if(!((n >> i) & 1) && inrange(m | (1 << i)))
                m |= 1 << i;
            if(((n >> i) & 1) && ((m >> i) & 1) && inrange(m & ~(1 << i)))
                m &= ~(1 << i);
        }
        for(int i=0; (1LL << i) <= n; i++)
            if(!((m>>i) & 1) && inrange(m | (1 << i)))
                m |= 1 << i;
        printf("%u\n",m);
    }
    return 0;
}

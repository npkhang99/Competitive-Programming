// CodeChef
#include <cstdio>
using namespace std;

int t, c, d, l;

int max(int a, int b){ return a > b? a:b; }

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&c,&d,&l);
        if(l % 4){
            printf("no\n");
            continue;
        }
        long long maxLeg = 4ll*d + 4ll*c, minLeg = 4ll*d + max(0, c - 2*d) * 4ll;
        if(minLeg <= l && l <= maxLeg) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

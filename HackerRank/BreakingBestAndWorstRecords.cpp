// HackerRank - University CodeSprint 2 - Breaking the Records
#include <cstdio>
using namespace std;

int n, min, max, ans1 = 0, ans2 = 0;

int main(){
    scanf("%d%d",&n,&min);
    max = min;
    for(int i=1; i<n; i++){
        int x; scanf("%d",&x);
        if(x > max) ans1++, max = x;
        else if(x < min) ans2++, min = x;
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}

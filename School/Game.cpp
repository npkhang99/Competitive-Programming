#include <stdio.h>
#include <set>
#include <math.h>
using namespace std;

const int N=10109;

int n;
set<int> a;

int main(){
    freopen("Game.inp","r",stdin);
    freopen("Game.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        a.insert(x);
    }

    set<int>::iterator last = a.end(), first = a.begin();
    last--;
    while(*first != *last){
        int diff = *last - *first;
        int decrease = (*first) * ceil(double(diff)/(*first));
        int next = *last - decrease;
        a.erase(last);
        a.insert(next);
        last = a.end(), first = a.begin(), last--;
    }
    printf("%d\n",*a.begin());
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int a, b, n;

ii max(ii a, ii b){
    if(a.second < b.second || (a.second == b.second && a.first > b.first)) return a;
    return b;
}

int main(){
    while(~scanf("%d %d %d",&a,&b,&n)){
        ii ans = ii(0,0);
        for(int i=0; i<=n/a; i++){
            int j = (n - i*a)/b;
            ii temp = ii(i + j, n - (i*a + j*b));
            if(ans == ii(0,0)) ans = temp;
            else ans = max(ans,temp);
        }
        if(!ans.second) printf("%d\n",ans.first);
        else printf("%d %d\n",ans.first,ans.second);
    }
    return 0;
}

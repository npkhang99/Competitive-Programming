#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int n, ans = 1;
ii a[10009];
multiset<ii> s;

int main(){
    // freopen("Meeting.inp","r",stdin);
    // freopen("Meeting.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n);
    s.insert(a[0]);
    for(int i=1; i<n; i++){
        while(!s.empty() && (*s.begin()).first <= a[i].second) s.erase(s.begin());
        s.insert(a[i]); ans = max(ans,(int)s.size());
    }
    // int l = 0, r = 0;
    // while(r < n){
    //     while(r < n && a[r].first < a[l].second) r+=1;
    //     ans = max(ans,r-l);
    //     while(l < r && a[r].first >= a[l].second) l+=1;
    // }
    printf("%d\n",ans);
    return 0;
}

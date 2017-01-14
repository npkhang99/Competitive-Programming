#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

#define fi first
#define se second

const int N = 100009;

int n, ans = 0, k = 1, c1 = 0, c2 = 0, a[3]={};
map<ii, set<ii> > b;

int min(int a, int b, int c){
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    return c;
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++)
            scanf("%d",&a[j]);
        sort(a,a+3);
        b[ii(a[0],a[1])].insert(ii(a[2],i));
        b[ii(a[0],a[2])].insert(ii(a[1],i));
        b[ii(a[1],a[2])].insert(ii(a[0],i));
        if(ans < a[0]) ans = a[0], c1 = i;
    }

    for(map<ii, set<ii> >::iterator it=b.begin(); it!=b.end(); it++)
        if(it->second.size() > 1){
            set<ii>::iterator it1 = it->se.end();
            int third = (*--it1).fi + (*--it1).fi;
            if(min((it->first).fi, (it->first).se, third) > ans){
                ans = min((it->first).fi, (it->first).se, third);
                k = 2;
                c1 = (*it1).se;
                c2 = (*++it1).se;
            }
        }

    if(k == 1) printf("1\n%d\n", c1);
    else printf("2\n%d %d\n",c1,c2);
    return 0;
}

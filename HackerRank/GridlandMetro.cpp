// HackerRank
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define x first
#define y1 second.first
#define y2 second.second

const int N = 1009;

int k;
ll n, m;
iii a[N];

int main(){
    scanf("%lld%lld%d",&n,&m,&k);
    for(int i=0; i<k; i++)
        scanf("%d%d%d",&a[i].x,&a[i].y1,&a[i].y2);

    ll ans = n*m;
    sort(a,a+k);
    for(int b=0; b<k;){
        int e=b;
        while(e < k && a[b].x == a[e].x) e++;
        int u = a[b].y1, v = a[b].y2, occupied = 0;
        for(int i=b; i<e; i++){
            if(a[i].y1 <= v){
                v = max(v,a[i].y2);
                continue;
            }
            occupied += v - u + 1;
            u = a[i].y1; v = a[i].y2;
        }
        occupied += v - u + 1;
        ans -= occupied;
        b = e;
    }
    printf("%lld\n",ans);
    return 0;
}

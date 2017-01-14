#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define fi first
#define se second

#define need se.fi
#define dead se.se

const int N = 200009;

int n;
iii a[N];

int main(){
    while(~scanf("%d",&n)){
        for(int i=0; i<n; i++){
            scanf("%d%d",&a[i].need,&a[i].dead);
            a[i].fi = a[i].need - a[i].dead;
            a[i].need = a[i].need;
            a[i].dead = a[i].dead;
        }
        sort(a,a+n);
        
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(ans < a[i].fi)
                ans = a[i].fi;
            ans += a[i].dead;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

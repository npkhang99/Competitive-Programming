#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

#define price first
#define fuel second

const int N = 200009;

int n, k, s, t, station[N]={};
ii car[N];

bool can(int f){
    int c = 0, time = 0;
    for(int i=1; i<=k+1; i++){
        int trip = station[i] - station[i-1];
        if(f < trip) return false;
        int a = min(trip, f-trip),
            use = 2*a + (trip-a),
            waste = a + (trip-a) * 2;
        if(time > t - waste) return false;
        time += waste;
    }
    return true;
}

int main(){
    scanf("%d%d%d%d",&n,&k,&s,&t);
    for(int i=0; i<n; i++)
        scanf("%d%d",&car[i].price,&car[i].fuel);
    for(int i=1; i<=k; i++)
        scanf("%d",&station[i]);
    station[0] = 0; station[k+1] = s;
    sort(station,station+k+2);

    int l = 1, r = 1000000000, require = 1000000009;
    while(l <= r){
        int mid = (l+r)/2;
        if(can(mid)){
            require = mid;
            r = mid - 1;
        }else l = mid + 1;
    }

    int ans = 1000000009;
    for(int i=0; i<n; i++)
        if(car[i].fuel >= require)
            ans = min(ans,car[i].price);
    printf("%d\n",ans == 1000000009? -1:ans);
    return 0;
}

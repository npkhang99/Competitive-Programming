#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<ll,ll> ii;

#define x first
#define y second

const int N = 300009;

int n;
ii a[N], O;
vector<ii> hull;

ll hullArea(){
    ll area = 0;
    hull.push_back(hull[0]);
    for(int i=0; i<hull.size()-1; i++)
        area += (hull[i+1].x - hull[i].x) * (hull[i+1].y + hull[i].y);
    return abs(area);
}

void shift(){
    int pos = 0;
    O = a[0];
    for(int i=1; i<n; i++)
        if(a[i].y == O.y && a[i].x < O.x) O = a[i];
        else if(a[i].y < O.y) O = a[i];

    for(int i=0; i<n; i++){
        a[i].x -= O.x;
        a[i].y -= O.y;
        if(a[i] == ii(0,0)) pos = i;
    }
    swap(a[0],a[pos]);
}

int ccw(ii a, ii b, ii c){
    ii u(b.x - a.y, b.y - a.y);
    ii v(c.x - b.x, c.y - b.y);
    ll t = u.x*v.y - u.y*v.x;
    if(!t) return 0;
    else if(t>0) return 1;
    else return -1;
}

int comp(ii a, ii b){
    return (a.x*b.y > b.x*a.y) || (a.x*b.y == b.x*a.y && a.y < b.y);
}

int main(){
    // freopen("bl.inp","r",stdin);
    // freopen("bl.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lld %lld",&a[i].x,&a[i].y);
    shift();
    sort(a+1,a+n,comp);
    // for(int i=0; i<n; i++)
    //     printf("%lld %lld\n",a[i].x,a[i].y);
    hull.push_back(a[0]); hull.push_back(a[1]); hull.push_back(a[2]);
    for(int i=3; i<n; i++){
        while(hull.size() > 1 && ccw(hull[hull.size()-2], hull[hull.size()-1], a[i]) <= 0) hull.pop_back();
        hull.push_back(a[i]);
    }
    printf("%d\n",(int)hull.size());
    for(int i=0; i<hull.size(); i++)
        printf("%lld %lld\n",hull[i].x + O.x,hull[i].y + O.y);
    printf("%.1lf\n",hull.size() > 2? hullArea()/2.0:0);
    return 0;
}

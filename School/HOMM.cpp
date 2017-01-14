#include <bits/stdc++.h>
using namespace std;

const int N=1009;

struct Point{
    double x, y, cotg;
    void set(double X, double Y){ x = X, y = Y; }
}a[N];

int n, ans[N]={}, c[N]={}, k = 0, cnt = 0;
double _x = 0, _y = 0;

int comp(Point a, Point b){
    return a.cotg > b.cotg;
}

void findLowestLeft(){
    _x = a[0].x, _y = a[0].y;
    for(int i=1; i<n; i++)
        if(a[i].y < _y) _x = a[i].x, _y = a[i].y;
        else if(a[i].y == _y && a[i].x < _x) _x = a[i].x, _y = a[i].y;
}

void move(){
    for(int i=0; i<n; i++){
        a[i].x -= _x;
        a[i].y -= _y;
        if(!a[i].y){
            if(a[i].x>0) a[i].cotg = DBL_MAX - 1;
            else if(a[i].x<0) a[i].cotg = DBL_MIN;
            else if(a[i].x==0) a[i].cotg = DBL_MAX;
        }else a[i].cotg = a[i].x/a[i].y;
    }
}

double triangleArea(Point a, Point b, Point c){
    return  (b.x - a.x) * (b.y + a.y) +
            (c.x - b.x) * (c.y + b.y) +
            (a.x - c.x) * (a.y + c.y);
}

double dist(Point a){
    return sqrt(pow(a.x,2.0) + pow(a.y,2.0));
}

void getFarthest(int i){
    if(dist(a[i]) > dist(a[c[k]])) c[k] = i;
}

void findHullContestantSet(){
    k = 1;
    for(int i=0; i<n; i++)
        if(!ans[i]){ c[k] = i; break; }
    for(int i=c[k]; i<n; i++){
        if(ans[i]) continue;
        if(a[i].cotg == a[c[k]].cotg) getFarthest(i);
        else c[++k] = i;
    }
}

int findHull(){
    findHullContestantSet();

    if(k <= 3){
        for(int i=1; i<=k; i++) ans[c[i]] = cnt;
        return k;
    }

    vector<int> hull;
    hull.push_back(c[1]); hull.push_back(c[2]);
    int s = 2;
    c[k+1] = c[1];
    for(int i=3; i<=k+1; i++){
        // if(ans[c[i]]) continue;
        printf("%lf\n",triangleArea(a[hull[s-1]],a[hull[s-2]],a[c[i]]));
        while(triangleArea(a[hull[s-1]],a[hull[s-2]],a[c[i]]) >= 0) hull.pop_back(), s-=1;
        hull.push_back(c[i]), s+=1;
    }
    for(int i=0; i<s; i++) ans[hull[i]] = cnt;
    return s;
}

int main(){
    // freopen("HOMM.inp","r",stdin);
    // freopen("HOMM.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        double x,y; scanf("%lf%lf",&x,&y);
        a[i].set(x,y);
    }
    findLowestLeft();
    move();
    sort(a,a+n,comp);
    int notCovered = n;
    while(notCovered) notCovered -= findHull(), printf("%d\n",notCovered);

    for(int i=0; i<n; i++) printf("%d\n",ans[i]);
    return 0;
}

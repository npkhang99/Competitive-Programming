#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> point;
typedef pair<int,int> ii;

#define x first
#define y second

const int N = 100009;

int n;
double sum = 0;
point a, b, c, t[N];

double dist(point source, point dest){
    return sqrt((source.x - dest.x)*(source.x - dest.x) + (source.y - dest.y)*(source.y - dest.y));
}

ii find(point a){
    int f = 0, s = -1;
    for(int i=0; i<n; i++)
        if(dist(a, t[i]) - dist(t[i], c) < dist(a, t[f]) - dist(t[f], c)) f = i;
    for(int i=0; i<n; i++)
        if(f != i && (s == -1 || dist(a, t[i]) - dist(t[i], c) < dist(a, t[s]) - dist(t[s], c))) s = i;
    return ii(f,s);
}

double one(){
    int p = 0;
    double l1, l2;

    for(int i=0; i<n; i++)
        if(dist(a,t[i]) - dist(t[i], c) < dist(a,t[p]) - dist(t[p], c)) p = i;
    l1 = sum + dist(a,t[p]) - dist(c,t[p]);

    for(int i=0; i<n; i++)
        if(dist(b,t[i]) - dist(t[i], c) < dist(b,t[p]) - dist(t[p], c)) p = i;
    l2 = sum + dist(b,t[p]) - dist(c,t[p]);

    return min(l1,l2);
}

double two(){
    double ret = 1e20;
    ii opt = find(b);
    for(int i=0; i<n; i++){
        int p = (i == opt.first? opt.second : opt.first);
        double temp = sum + dist(a, t[i]) - dist(t[i], c) + dist(b, t[p]) - dist(t[p], c);
        ret = min(ret, temp);
    }
    return ret;
}

int main(){
    while(~scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y)){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%lf %lf", &t[i].x, &t[i].y);

        sum = 0.0;
        for(int i=0; i<n; i++)
            sum += 2.0*dist(c, t[i]);

        double ans = one();

        if(n > 1) ans = min(ans, two());

        printf("%.12lf\n", ans);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1009;

#define EPS 1e-9;

struct point{
    int x, y, id;
}red[N], green[N];

struct anotherPoint{
    int id;
    double cotg;
}a[N];

int n;

bool comp(anotherPoint a, anotherPoint b){
    return a.cotg < b.cotg;
}

bool equal(double a, double b){
    return fabs(a - b) < EPS;
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &green[i].x, &green[i].y);
        green[i].id = i+1;
    }
    for(int i=0; i<n; i++){
        scanf("%d%d", &red[i].x, &red[i].y);
        red[i].id = i+n+1;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            int x = red[i].x - green[k].x,
                y = red[i].y - green[k].y;
            a[i].id = red[i].id;
            if(y == 0) a[i].cotg = DBL_MAX;
            else a[i].cotg = x / y;
        }

        sort(a,a+n,comp);

        for(int i=0; i<n-1; i++)
            if(equal(a[i].cotg, a[i+1].cotg)){
                printf("%d %d %d\n", green[k].id, a[i].id, a[i+1].id);
                return 0;
            }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            int x = green[i].x - red[k].x,
                y = green[i].y - red[k].y;
            a[i].id = green[i].id;
            if(y == 0) a[i].cotg = DBL_MAX;
            else a[i].cotg = x / y;
        }

        sort(a,a+n,comp);

        for(int i=0; i<n-1; i++)
            if(equal(a[i].cotg, a[i+1].cotg)){
                printf("%d %d %d\n", red[k].id, a[i].id, a[i+1].id);
                return 0;
            }
    }

    printf("-1\n");
    return 0;
}

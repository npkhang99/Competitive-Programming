/* Graham's Algorithm in finding a convex hull
 * Time complexity: O(n log n)
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define x first
#define y second

const int N = 100009;

int n, sz;
ii origin, a[N]={};

void operator -= (ii &A, ii B){
    A.x -= B.x; A.y -= B.y;
}

bool ccw(ii O, ii A, ii B){
    A -= O; B -= O;
    return A.x * B.y > A.y * B.x;
}

int comp(ii A, ii B){
    return ccw(origin, A, B);
}

void convex(){
    sort(a+1, a+n+1);
    origin = a[1];
    sort(a+2, a+n+1, comp);         // must be a+2
    a[0] = a[n]; a[n+1] = a[1];
    int j=1;
    for(int i=1; i<=n+1; i++){
        while (j>2 && !ccw(a[j-2], a[j-1], a[i])) j--;
        a[j++]=a[i];
    }
    n=j-2;
}

int main(){
    while(~scanf("%d", &n), n){
        for(int i=1; i<=n; i++)
            scanf("%d %d", &a[i].x, &a[i].y);
        
        if(n > 1) convex();
        else n = 0;

        printf("%d\n", n);
        for(int i=1; i<=n; i++)
            printf("%d %d\n", a[i].x, a[i].y);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 59;

struct circle{
    int x, y, r;
}a[N];

int n;

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r), a[i].r *= 10;
    return 0;
}

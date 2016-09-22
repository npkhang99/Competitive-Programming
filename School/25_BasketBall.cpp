#include <bits/stdc++.h>
using namespace std;

struct robot{
    int h,w,s;
}a[24];

int n, H;
long long dp[24][1<<21];

int main(){
    scanf("%d%d",&n,&H);
    for(int i=0; i<n; i++){
        scanf("%d%d%d",&a[i].h,&a[i].w,&a[i].s);
        temp += a[i].h;
    }
    if(temp<h){
        printf("H is too tall\n");
        return 0;
    }

    return 0;
}

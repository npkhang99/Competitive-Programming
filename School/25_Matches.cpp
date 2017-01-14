#include <bits/stdc++.h>
using namespace std;

const int a[] = {6,2,5,5,4,5,6,3,7,6};

int n, next=10;
long long ans = 0;

void btrack(int j, int total){
    ans+=1;
    if(total==n) return;
    for(int i=0; i<10; i++)
        if(total+a[i]<=n) btrack(i,total+a[i]);
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<10; i++) btrack(i,a[i]);
    printf("%lld\n",ans);
    return 0;
}

#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef pair<int,int> ii;

int n;
ii a[1000009];

int GCD(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b){
    return a*b/GCD(a,b);
}

bool check(int a, int b){
    int r = GCD(a,b);
    return a == r;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        int k = 0;
        for(int i=n+1; i<=n*2; i++){
            int r = LCM(n,i);
            if(check(r/n-r/i,r)) a[k++] = ii(r/GCD(r/n-r/i,r),i);
        }
        printf("%d\n",k);
        for(int i=0; i<k; i++)
            printf("1/%d = 1/%d + 1/%d\n",n,a[i].first,a[i].second);
    }
    return 0;
}

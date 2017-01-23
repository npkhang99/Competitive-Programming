#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 109;

int n, a[N]={}, b[N]={};

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]), b[i] = b[i-1] + a[i];

    int flag = true;
    for(int i=1; i<=n; i++)
        if(a[i]) flag = false;
    if(flag){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    if(b[n]){
        printf("1\n1 %d\n", n);
        return 0;
    }
    for(int i=1; i<=n; i++)
        if(a[i] && b[i] != b[i-1]){
            printf("2\n1 %d\n%d %d\n",i,i+1,n);
            break;
        }
    return 0;
}

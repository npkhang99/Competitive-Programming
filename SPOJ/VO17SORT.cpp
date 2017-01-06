#include <bits/stdc++.h>
using namespace std;

const int N = 19;

int n, a[N]={};

int aIs(int x, int y, int z){
    return a[1] == x && a[2] == y && a[3] == z;
}

void solution1(){
    if(aIs(3,2,1)) printf("2\n");
    else printf("1\n");
}

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        bool flag = false;
        for(int i=1; i<=n; i++)
            if(a[i] != i){
                flag = true;
                break;
            }
        if(!flag){
            printf("0\n");
            continue;
        }
        if(n <= 3) solution1();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, a[N]={};

int main(){
    int TC; scanf("%d",&TC);
    for(int T=0; T<TC; T++){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int l=0, r=n-1, ans = 0;
        while(l <= r){
            int top = a[r--], items = 1;
            while(l <= r && top * items < 50) l++, items++;
            if(top * items >= 50) ans++;
        }
        printf("Case #%d: %d\n", T+1, ans);
    }
    return 0;
}

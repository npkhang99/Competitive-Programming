#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, w, b;

int main(){
    ios::sync_with_stdio(false);
    while(cin>> n>> b>> m>> w){
        int ans=10E8;
        for(int i=0; i<m; i++){
            int cost, have;
            cin>> cost;
            for(int j=0; j<w; j++){
                cin>> have;
                if(have>=n) ans = min(ans,cost*n);
            }
        }
        if(ans>b) printf("stay home\n");
        else printf("%d\n",ans);
    }
    return 0;
}

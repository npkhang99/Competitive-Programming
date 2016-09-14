#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;

int n, k, c, r, a[N]={};

int main(){
    while(cin>> k, k>0){
        cin>> n;
        for(int i=0; i<N; i++) a[i] = 0;
        for(int i=0; i<k; i++){
            int x; cin>> x;
            a[x] = 1;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int cnt=0;
            cin>> c>> r;
            for(int j=0; j<c; j++){
                int x; cin>> x;
                if(a[x]) cnt+=1;
            }
            if(cnt>=r) ans+=1;
        }
        if(ans==n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
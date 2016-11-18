#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int N=3009;

int n, a[N], before, after;

int main(){
    ios::sync_with_stdio(false);
    while(cin>> n){
        for(int i=0; i<n; i++) a[i] = 0;
        cin>> before;
        for(int i=1; i<n; i++){
            cin>> after;
            a[abs(before-after)] = 1;
            before = after;
        }
        int isJ = 1;
        for(int i=1; i<n; i++)
            if(!a[i]){ isJ = 0; break; }
        if(isJ) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}

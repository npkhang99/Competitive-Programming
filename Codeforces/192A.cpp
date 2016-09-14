#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int n, k=1;
map<int,int> a;

int main(){
    cin>> n;
    for(long long i=1; i<=n; i++){
        long long curr = (i*(i+1))/2;
        if(curr>n) break;
        a[curr] = 1;
        int need = n-curr;
        if(a[need]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

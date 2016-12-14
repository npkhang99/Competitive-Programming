#include <bits/stdc++.h>
using namespace std;

const int d[] = {0,1,3,5,7,9};

int x, n, a[5e6]={}, key, R;
char st[10];

void preprocess(int i, int d){
    if(i == 8){
        a[n++] = d;
        return;
    }
    for(int j=(i==7 || d); j<6; j++)
        preprocess(i+1, d[j] * (int)pow(10,(7-i)) + d);
}

int findLeft(int L, int R, int X){

}

int main(){
    preprocess(0,0);
    while(scanf("%s%d  ",st,&x) == 2){
        key = lower_bound(a,a+n,x/2);
        R = lower_bound(a,a+n,x);
        if(2*a[key] > x) key-=1;
        if(a[R] > x) r-=1;

        int l = 0, r = 0, ans = 1e9;
        while(l <= key){
            r = lower_bound()
        }
    }
    return 0;
}

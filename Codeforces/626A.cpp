#include <iostream>
#include <string>
using namespace std;

#define long long long

int n, u, l, d, r;
string st;

void inc(int ch){
    switch(ch){
        case (int)'U': u++; break;
        case (int)'L': l++; break;
        case (int)'D': d++; break;
        case (int)'R': r++; break;
    }
}

void proc(){
    long count=0;
    for(int i=0; i<n; i++){
        u=l=d=r=0;
        for(int j=i; j<n; j++){
            inc(st[j]);
            if(u==d && l==r) count++;
        }
    }
    cout<< count;
}

int main(){
    cin>> n>> st;
    proc();
    return 0;
}

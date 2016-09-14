#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int l=1, r=1000000, j=0;
string st;

int main(){
    while(l<=r){
        j=(l+r)/2;
        printf("%d\n",j);
        fflush(stdout);
        cin>> st;
        if(st=="<") r=j-1;
        else l=j+1;
    }
    printf("! %d\n",r);
    fflush(stdout);
    return 0;
}

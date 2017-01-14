#include <iostream>
#include <stdio.h>
using namespace std;

int a,b,t;

int main(){
    cin>> t;
    for(int i=0; i<t; i++){
        cin>> a>> b;
        printf("Case %d: %d\n",i+1,a+b);
    }
    return 0;
}

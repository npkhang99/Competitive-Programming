#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    double v=0,t=0;
    while(cin>> v>> t){
        if(t!=0){
            double a = v/t;
            cout<< 0.5*a*4*t*t<< endl;
        }else printf("0\n");
    }
    return 0;
}
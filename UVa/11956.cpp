#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int n = 100;

int a[109]={}, T, pos=0;
string st;

void init(){
    pos = 0;
    for(int i=0; i<n; i++) a[i]=0;
}

void incpos(int x){
    pos = (pos+x+100)%100;
}

void inc(int x){
    a[pos] = (a[pos]+x+256)%256;
}

int main(){
    scanf("%d\n",&T);
    for(int test=0; test<T;){
        st = "";
        cin>> st;
        init();
        for(int i=0; i<st.size(); i++){
            if(st[i]=='>') incpos(1);
            if(st[i]=='<') incpos(-1);
            if(st[i]=='+') inc(1);
            if(st[i]=='-') inc(-1);
        }
        printf("Case %d:",++test);
        for(int i=0; i<n; i++)
            printf(" %02X",a[i]);
        printf("\n");
    }
    return 0;
}

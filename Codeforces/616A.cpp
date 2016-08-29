#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string a, b;

int comp(int i, int j){
    if(a.length()-i > b.length()-j) return 1;
    if(a.length()-i < b.length()-j) return -1;
    for(int x=0; x<a.length()-i; x++)
        if(a[x+i]>b[x+j]) return 1;
        else if(a[x+i]<b[x+j]) return -1;
    return 0;
}

void xuly(){
    int i=0, j=0;
    while(i<a.length() && a[i]=='0') i++;
    while(j<b.length() && b[j]=='0') j++;
    int ans=comp(i,j);
    if(ans==-1) printf("<");
    else if(ans==0) printf("=");
    else printf(">");
}

int main(){
    cin>> a>> b;
    xuly();
    return 0;
}

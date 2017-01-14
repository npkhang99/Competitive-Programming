#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int a[256] = {};
string st;

int abs(int x){ return x<0? -x:x; }

int main(){
    cin>> st;
    if(st.size()%2){
        printf("-1\n");
        return 0;
    }
    for(int i=0; i<st.size(); i++) a[st[i]]+=1;
    int ans = 10E8;
    if(abs(a['U']-a['D']) == abs(a['L']-a['R'])) ans = abs(a['U']-a['D']);
    else if(abs(a['U']-a['D']) == 0) ans = min(ans,abs(a['L']-a['R'])/2);
    else if(abs(a['L']-a['R']) == 0) ans = min(ans,abs(a['U']-a['D'])/2);
    else ans = min(ans,abs(a['U']-a['D']) + abs(a['L']-a['R']))/2;
    printf("%d\n",ans);
    return 0;
}

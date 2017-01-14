#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct time{
    int k,s;
}a[109];

int n, s1=0, s2=0, t1=0, t2=0, s0=0;

int abs(int x){ return (x<0)?-x:x; }

int main(){
    // freopen("Basket_B.inp","r",stdin);
    // freopen("Basket_B.out","w",stdout);
    cin>> n;
    for(int i=0; i<n; i++){
        string st;
        cin>> a[i].k>> st;
        int tm = (int(st[0])-48)*10+(int(st[1])-48);
        int ts = (int(st[3])-48)*10+(int(st[4])-48);
        a[i].s=60*tm+ts;
    }
    a[n].k=0; a[n].s=48*60;
    
    for(int i=0; i<=n; i++){
        if(t1>t2) s1+=a[i].s-s0;
        if(t2>t1) s2+=a[i].s-s0;
        if(a[i].k==1) t1+=1;
        else if(a[i].k==2) t2+=1;
        s0=a[i].s;
    }
    printf("%02d:%02d\n%02d:%02d\n",s1/60,s1%60,s2/60,s2%60);
    return 0;
}

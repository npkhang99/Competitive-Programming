#include <bits/stdc++.h>
using namespace std;

const int N = 300009;

int only_usb, only_ps2, both, n;
priority_queue<int, vector<int>, greater<int> > usb, ps2;

int main(){
    scanf("%d%d%d", &only_usb, &only_ps2, &both);
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int price; char type[10];
        scanf("%d %s", &price, type);
        if(!strcmp(type, "USB")) usb.push(price);
        else ps2.push(price);
    }

    long long equipped = 0, money = 0;

    while(only_usb && !usb.empty()){
        equipped++; only_usb--;
        money += usb.top();
        usb.pop();
    }

    while(only_ps2 && !ps2.empty()){
        equipped++; only_ps2--;
        money += ps2.top();
        ps2.pop();
    }

    while(both && (!usb.empty() || !ps2.empty())){
        int p1 = 1e9 + 7, p2 = 1e9 + 7;
        if(!usb.empty()) p1 = usb.top();
        if(!ps2.empty()) p2 = ps2.top();
        equipped++; both--;
        money += min(p1, p2);
        if(p1 < p2) usb.pop();
        else ps2.pop();
    }

    printf("%lld %lld\n", equipped, money);
    return 0;
}

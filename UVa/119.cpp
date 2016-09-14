#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

const int N=19;

int n;
string a[N];
map<string,int> ans;

int main(){
    cin>> n;
    while(true){
        for(int i=0; i<n; i++){
            cin>> a[i];
            ans[a[i]]=0;
        }
        for(int i=0; i<n; i++){
            string name;
            int money, giftNum;
            cin>> name>> money>> giftNum;
            if(giftNum==0) continue;
            int eachGiftCost = money/giftNum, left=money-eachGiftCost*giftNum;
            ans[name]-=money-left;
            for(int j=0; j<giftNum; j++){
                cin>> name;
                ans[name] += eachGiftCost;
            }
        }
        for(int i=0; i<n; i++) printf("%s %d\n",a[i].c_str(),ans[a[i]]);
        if(cin>> n) printf("\n");
        else break;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
string t;

int main(){
    while(cin>> n>> t){
    int hour = (t[0]-48)*10 + t[1]-48;
    int minute = (t[3]-48)*10 + t[4]-48;
    if(n == 12){
        if(hour>12 && hour%10==0) hour = 10;
        if(hour>12) hour = hour%10;
        if(!hour) hour = 1;
    }else{
        if(hour>23) hour = 10 + hour%10;
    }
    if(minute > 59) minute = 40 + minute%10;
    printf("%02d:%02d\n",hour,minute);}
    return 0;
}

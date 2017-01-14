#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

int n, x, k=0;
string st, a[1000009]={};
priority_queue<int, vector<int>, greater<int> > q;

void xuly(){
    if(st=="insert"){
        q.push(x); a[k++] = "insert "+to_string(x);
        return;
    }
    while(!q.empty() && q.top()<x){
        q.pop(); a[k++] = "removeMin";
    }
    if(q.empty() || q.top()!=x){
        q.push(x); a[k++] = "insert "+to_string(x);
    }
    if(q.top()==x) a[k++] = "getMin "+to_string(x);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> st;
        if(st=="removeMin"){
            if(q.empty()){
                a[k++] = "insert "+to_string(0);
            }else q.pop();
            a[k++] = "removeMin"; continue;
        }
        cin>> x;
        xuly();
    }
    printf("%d\n",k);
    for(int i=0; i<k; i++) printf("%s\n",a[i].c_str());
    return 0;
}

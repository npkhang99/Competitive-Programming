#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

#define abs(x) (x<0)?-x:x

const int N=100009;

int n, a[N]={};

long long xuly(){
    long long ans=0;
    int u=-2, v=20009;
    priority_queue<int> gr(a,a+n);
    priority_queue<int,vector<int>,greater<int> > le(a,a+n);
    if(gr.top()-le.top()<2) return 0;
    while(abs(gr.top()-le.top())>1){
        if(u<gr.top()){
            gr.push(u);
            u=gr.top(); gr.pop();
        }
        if(v>le.top()){
            le.push(v);
            v=le.top(); le.pop();
        }
        while(u>=gr.top() && abs(u-v)>1){
            if(v>le.top()){
                le.push(v);
                v=le.top(); le.pop();
            }
            printf("%d %d - ",u,v);
            u-=1; v+=1;
            ans+=1;
            printf("%d %d\n",u,v);
            // if(!gr.empty() && !le.empty() && u-gr.top()<2) break;
        }
    }
}

int main(){
    cin>> n;
    for(int i=0; i<n; i++) cin>> a[i];
    cout<< xuly();
    return 0;
}

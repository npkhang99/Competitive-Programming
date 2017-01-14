#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

int n, isStack=1, isQueue=1, isPQueue=1;;
stack<int> s;
queue<int> q;
priority_queue<int> pq;

void reset(){
    while(!s.empty()) s.pop();
    while(!q.empty()) q.pop();
    while(!pq.empty()) pq.pop();
    isStack=1, isQueue=1, isPQueue=1;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        reset();
        for(int i=0; i<n; i++){
            int x,y; scanf("%d%d",&x,&y);
            if(x==1){
                if(isStack) s.push(y);
                if(isQueue) q.push(y);
                if(isPQueue) pq.push(y);
                continue;
            }

            int u=0;

            if(isStack && !s.empty()){
                u = s.top(); s.pop();
                if(u!=y) isStack=0;
            }else isStack=0;

            if(isQueue && !q.empty()){
                u = q.front(); q.pop();
                if(u!=y) isQueue=0;
            }else isQueue=0;

            if(isPQueue && !pq.empty()){
                u = pq.top(); pq.pop();
                if(u!=y) isPQueue=0;
            }else isPQueue=0;
        }
        if(isStack + isQueue + isPQueue==0){ printf("impossible\n"); continue; }
        if(isStack + isQueue + isPQueue>1){ printf("not sure\n"); continue; }
        if(isStack) printf("stack\n");
        if(isQueue) printf("queue\n");
        if(isPQueue) printf("priority queue\n");
    }
    return 0;
}

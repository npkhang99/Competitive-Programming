#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

int n;
stack<int> s;
queue<int> q;
priority_queue<int> pq;

int main(){
	freopen("guessDST.inp","r",stdin);
	freopen("guessDST.out","w",stdout);
	cin>> n;
	int isStack=1, isQueue=1, isPQueue=1;
	for(int i=0; i<n; i++){
		int x,y; cin>> x>> y;
		if(x==1){
			s.push(y);
			q.push(y);
			pq.push(y);
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
		if(isStack+isQueue+isPQueue==0){ printf("impossible\n"); break; }
	}
	if(isStack+isQueue+isPQueue>1){ printf("not sure\n"); return 0; }
	if(isStack) printf("stack\n");
	if(isQueue) printf("queue\n");
	if(isPQueue) printf("priority queue\n");
	return 0;
}

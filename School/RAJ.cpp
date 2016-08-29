#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

const int N=200009;

int n, m, s, d, a[N];
void doc(){
	cin>> n>> m>> s>> d;
	a[0]=0;
	for(int i=1; i<=n; i++) cin>> a[i];
	a[n+1]=INT_MAX;
}

void xuly(){
	sort(a,a+n+1);
	stack<int> st;
	for(int i=n+1; i>0; i--) st.push(a[i]);
	int lastPos=0, runLen=0, jumpLen=0;
	while(!st.empty()){
		int nextObs = st.top();
		if(nextObs==INT_MAX){
			st.pop(); break;
		}
		int _runLen=nextObs - lastPos -1;
		if(_runLen<s) break; st.pop();
		runLen+=_runLen; lastPos=nextObs-1;
		int maxPos=nextObs-1+d, landPos=nextObs+1, t=0;
		if(!st.empty()) t=st.top()-1;
		while(t>0 && t-nextObs<s){
			nextObs=t+1; st.pop();
			t=st.top()-1;
			landPos=nextObs+1;
		}
		if(!st.empty() && landPos>maxPos) { printf("-1\n"); return; }
		jumpLen+=landPos-lastPos;
		lastPos=landPos;
	}
	if(st.empty()) printf("%d %d\n", m-jumpLen, jumpLen);
	else printf("-1\n");
}

int main(){
	freopen("RAJ.inp","r",stdin);
	// freopen("RAJ.out","w",stdout);
	doc();
	xuly();
	return 0;
}

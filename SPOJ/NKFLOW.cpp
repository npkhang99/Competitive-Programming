// SPOJ submission 15923140 (C++ 5) plaintext list. Status: AC, problem NKFLOW, contest SPOJVN. By mansblacks (Khang), 2015-12-23 07:20:45.
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <memory.h>
using namespace std;
 
const int N=1009;
int n, m, s, t, c[N][N], f[N][N], tr[N];
//---------------------------------------------------------
void doc(){
	cin>> n>> m>> s>> t;
	for(int i=1; i<=m; i++){
		int x,y,val;
		cin>> x>> y>> val;
		c[x][y]=val;
	}
}
//---------------------------------------------------------
int flowVal(){
	int val=INT_MAX;
	for(int v=t,u=tr[t]; v!=s; v=u,u=tr[v])
		val=min(val, c[u][v]-f[u][v]);
	return val;
}
//---------------------------------------------------------
int find(){
	queue<int> qu;
	memset(tr,0,sizeof(tr));
	qu.push(s); tr[s]=-1;
	while(!qu.empty()){
		int u=qu.front(); qu.pop();
		if(u==t) return flowVal();
		for(int v=1; v<=n; v++)
			if(!tr[v] && c[u][v]-f[u][v]>0){
				tr[v]=u; qu.push(v);
			}
	}
	return 0;
}
//---------------------------------------------------------
void updateFlow(int val){
	for(int v=t,u=tr[t]; v!=s; v=u,u=tr[v]){
		f[u][v]+=val; f[v][u]-=val;
	}
}
//---------------------------------------------------------
void xuly(){
	int found, flow=0;
	do{
		flow+=found=find();
		if(found) updateFlow(found);
	}while(found);
	/*for(int i=1; i<=n; i++)
		if(i!=s) fmax+=f[s][i];*/
	cout<< flow;
}
//---------------------------------------------------------
int main(){
	doc();
	xuly();
	return 0;
} 
#include <iostream>
#include <stdio.h>
#include <queue>
#include <memory.h>
#include <limits.h>
#define for(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

const int dx[]={1,1,-1,-1};
const int dy[]={-1,1,1,-1};
int a[400][400], n, p, q, s, t;
bool b[400][400];
//---------------------------------------------------------
void doc(){
	int m, x, y;
	cin>> n>> m>> p>> q>> s>> t;
	p=n-p+1; s=n-s+1;
	memset(b,0,sizeof(b));
	for(i,1,n)
		for(j,1,n) a[i][j]=INT_MAX;
	for(i,1,m){
		cin>> x>> y;
		b[n-x+1][y]=true;
	}
	for(i,0,n+1){
		b[0][i]=true;
		b[i][0]=true;
	}
}
//---------------------------------------------------------
bool straight(int x,int y,int u,int v, int s, int t){
	return (x-u==u-s && y-v==v-t);
}
//---------------------------------------------------------
int cal(int x,int y,int u,int v, int s, int t){
	if (straight(x,y,u,v,s,t)) return 0;
	else return 1;
}
//---------------------------------------------------------
void xuly(){
	queue<int> qx,qy,xt,yt;
	int x, y, u, v, xtr, ytr;
	a[p][q]=0; b[p][q]=true;
	qx.push(p); qy.push(q); xt.push(p); yt.push(q);
	while (!b[s][t] && !qx.empty()){
		x=qx.front(); y=qy.front();
		xtr=xt.front(); ytr=yt.front();
		qx.pop(); qy.pop(); xt.pop(); yt.pop();
		for(i,0,3){
			u=x+dx[i]; v=y+dy[i];
			if (!b[u][v] && a[u][v]>=a[x][y]+cal(u,v,x,y,xtr,ytr)){
				a[u][v]=a[x][y]+cal(u,v,x,y,xtr,ytr);
				qx.push(u); qy.push(v);
				xt.push(x); yt.push(y);
			}
		}
	}
	for(i,1,n){
		for(j,1,n)
			if (a[i][j]==INT_MAX) cout<< "0 ";
			else cout<< a[i][j]<< " ";
		cout<< endl;
	}
}
//---------------------------------------------------------
int main(){
	freopen("QBBishop.inp", "r", stdin);
	//freopen("QBBishop.out", "w", stdout);
	doc();
	xuly();
	if (a[s][t]!=INT_MAX)cout<< a[s][t];
	else cout<< "-1";
	return 0;
}
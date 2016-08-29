#include<iostream>
#include<stdio.h>
#include<queue>
#include<memory.h>
#include<algorithm>
using namespace std;

const int N=1009;
const int dx[]={-2,-2,-1,1};
const int dy[]={-1,1,2,2};
int a[N][N], n, m, p, q;
queue<int> qx, qy;
//---------------------------------------------------------
void _push(int i, int j){
	qx.push(i); qy.push(j);
}
//---------------------------------------------------------
void _pop(){
	qx.pop(); qy.pop();
}
//---------------------------------------------------------
bool inSide(int i, int j){
	return i>0 && i<=n && j>0 && j<=m;
}
//---------------------------------------------------------
void xuly(){
	memset(a,-1,sizeof(a));
	a[n][1]=0; a[n][2]=0; a[n-1][1]=0; a[n-1][2]=0;
	_push(n,1); _push(n,2); _push(n-1,1); _push(n-1,2);
	while(!qx.empty()){
		int x=qx.front();
		int y=qy.front();
		_pop();
		for(int i=0; i<=3; i++){
			int u=x+dx[i];
			int v=y+dy[i];
			if(inSide(u,v) && a[u][v]==-1){
				_push(u,v);
				a[u][v]=max(a[u][v], 1-a[x][y]);
			}
		}
	}
	/*for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) cout<< a[i][j]<< " ";
		cout<< endl;
	}*/
}
//---------------------------------------------------------
int main(){
	freopen("Horse.inp","r",stdin);
	freopen("Horse.out","w",stdout);
	cin>> n>> m>> p>> q;
	p=n-p+1;
	xuly();
	cout<< a[p][q];
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
using namespace std;

const int N=1009;
const int dx[] = {-1,-1,0,1,1,1,0,-1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};

int n, m, a[N][N], c[N][N]={};
deque<int> qx,qy;

int canGo(int u, int v){
	return u>0 && u<n-1 && v>=0 && v<m;
}

void BFS(){
	while(!qx.empty()){
		int x = qx.front(),
			y = qy.front();
		qx.pop_front(); qy.pop_front();
		for(int i=0; i<8; i++){
			int u = x+dx[i], v = y+dy[i];
			if(canGo(u,v) && c[u][v] > c[x][y]+a[u][v]){
				c[u][v] = c[x][y]+a[u][v];
				if(!a[u][v]){
					qx.push_front(u); qy.push_front(v);
					continue;
				}
				qx.push_back(u); qy.push_back(v);
			}
		}
	}
}

int main(){
	// freopen("PATH.inp","r",stdin);
	// freopen("PATH.out","w",stdout);
	cin>> n>> m;
	for(int i=0; i<n; i++){
		string st; cin>> st;
		for(int j=0; j<m; j++){
			if(st[j]=='.') a[i][j] = 1;
			else a[i][j] = 0;
			c[i][j] = 10E8;
		}
	}
	for(int i=1; i<n-1; i++){
		qx.push_back(i);
		qy.push_back(0);
		c[i][0] = a[i][0];
	}
	BFS();
	int ans = 10E8;
	for(int i=1; i<n-1; i++){
		// printf("%d ",c[i][m-1]);
		ans = (ans>c[i][m-1])? c[i][m-1]:ans;
	}
	printf("%d\n",ans);
	return 0;
}
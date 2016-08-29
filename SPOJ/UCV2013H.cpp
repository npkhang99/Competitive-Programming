// SPOJ submission 17415953 (C++ 5) plaintext list. Status: AC, problem UCV2013H, contest SPOJ. By mansblacks (Khang), 2016-08-02 06:47:04.
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int N=259;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};

int n, m, a[N][N]={}, b[N*N]={};

int canGo(int x, int y){
	return x>=0 && x<n && y>=0 && y<m && a[x][y]==1;
}

int BFS(int s, int t){
	int areaSize=0;
	queue<int> qx, qy;
	qx.push(s); qy.push(t);
	while(!qx.empty()){
		int x=qx.front(); qx.pop();
		int y=qy.front(); qy.pop();
		if(a[x][y]!=1) continue;
		a[x][y]=2; areaSize+=1;
		for(int i=0; i<4; i++){
			int u=x+dx[i], v=y+dy[i];
			if(canGo(u,v)){
				qx.push(u); qy.push(v);
			}
		}
	}
	return areaSize;
}

void xuly(){
	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j]==1){
				b[BFS(i,j)]+=1;
				ans+=1;
			}
	printf("%d\n",ans);
	if(!ans) return;
	for(int i=1; i<=n*m; i++)
		if(b[i]){
			printf("%d %d\n",i,b[i]);
			b[i] = 0;
		}
}

int main(){
	while(scanf("%d%d",&n,&m), n || m){
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d",&a[i][j]);

		xuly();
	}
	return 0;
}

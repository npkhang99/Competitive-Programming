#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
using namespace std;

const int N=1009;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n, a[N][N], b[N][N]={}, c[N][N]={}, m, Q;
deque<int> qx, qy;

int canGo(int u, int v){
	return u>=0 && u<n && v>=0 && v<m;
}

void BFS(){
	while(!qx.empty()){
		int x = qx.front(),
			y = qy.front();
		qx.pop_front(); qy.pop_front();
		for(int i=0; i<4; i++){
			int u = x+dx[i], v = y+dy[i], inc = a[u][v]!=a[x][y];
			if(canGo(u,v) && c[u][v]>c[x][y]+inc){
				c[u][v] = c[x][y] + inc;
				if(!inc){
					qx.push_front(u); qy.push_front(v);
					continue;
				}
				qx.push_back(u); qy.push_back(v);
			}
		}
	}
}

int main(){
	// freopen("PATHGAME.inp","r",stdin);
	// freopen("PATHGAME.out","w",stdout);
	scanf("%d%d%d\n",&n,&m,&Q);
	for(int i=0; i<n; i++){
		char ch[N];
		scanf("%[^\n]\n",ch);
		for(int j=0; j<=m; j++){
			if(ch[j]=='*'){
				qx.push_back(i);
				qy.push_back(j);
				a[i][j] = c[i][j] = 0;
			}else{ a[i][j] = ch[j]-'A'+1; c[i][j] = 10E8; }
		}
	}
	BFS();
	for(int i=0; i<Q; i++){
		int x,y;
		scanf("%d%d\n",&x,&y);
		printf("%d\n",c[x-1][y-1]);
	}
	return 0;
}
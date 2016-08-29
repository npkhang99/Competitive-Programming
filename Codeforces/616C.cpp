#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int N=1009;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

int n, m, size[N][N]={}, b[N][N]={}, group[N][N]={}, grCheck[N*N]={}, k=0;
char a[N][N];
queue<int> qx, qy;

void reset(){
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			b[i][j] = false;
}

int inSide(int u, int v){
	return u>=0 && u<n && v>=0 && v<m;
}

int canGo(int u, int v){
	return inSide(u,v) && !b[u][v] && a[u][v]=='.';
}

int BFS(int s, int t, int gr){
	vector<int> vx, vy;
	int cnt=0;
	qx.push(s), qy.push(t); b[s][t] = true;
	while(!qx.empty()){
		int x = qx.front(), y = qy.front();
		vx.push_back(x), vy.push_back(y);
		qx.pop(), qy.pop();
		cnt+=1;
		for(int i=0; i<4; i++){
			int u = x+dx[i], v = y+dy[i];
			if(canGo(u,v)) b[u][v] = true, qx.push(u), qy.push(v);
		}
	}
	for(int i=0; i<vx.size(); i++)
		size[vx[i]][vy[i]] = vx.size(),
		group[vx[i]][vy[i]] = gr;
	return cnt;
}

int main(){
	scanf("%d%d\n",&n,&m);
	for(int i=0; i<n; i++) scanf("%s\n",&a[i]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j]=='.' && !size[i][j])
				BFS(i,j,++k);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]=='.'){
				printf(".");
				continue;
			}
			int s=1;
			for(int k=0; k<4; k++)
				if(inSide(i+dx[k],j+dy[k]) && !grCheck[group[i+dx[k]][j+dy[k]]])
					s+=size[i+dx[k]][j+dy[k]], grCheck[group[i+dx[k]][j+dy[k]]]=1;
			for(int k=0; k<4; k++)
				if(inSide(i+dx[k],j+dy[k])) grCheck[group[i+dx[k]][j+dy[k]]]=0;
			printf("%d",s%10);
		}
		printf("\n");
	}
	return 0;
}

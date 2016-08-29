#include <iostream>	// cin cout
#include <stdio.h>	// freopen
#include <queue>	// queue push pop top
#define fi "BFS.inp"
using namespace std;

const int N=100009;

int n, a[N][N]={}, b[N]={};
//---------------------------------------------------------
void docfile(){
	cin>> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) cin>> a[i][j];
}
//---------------------------------------------------------
void BFS(){
	queue<int> q;
	q.push(1); b[1]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		cout<< u<< " ";
		for(int v=1; v<=n; v++)
			if(a[u][v]==1 && !b[v]){
				q.push(v);
				b[v]=1;
			}
	}
}
//---------------------------------------------------------
int main(){
	freopen(fi,"r",stdin);
	docfile();
	BFS();
	return 0;
}

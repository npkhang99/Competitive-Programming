#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int N=10009;

typedef pair<int,int> ii;

int n, m, a[N][N]={}, b[N]={}, c[N]={};
vector<int> g[N];

int prim(){
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	pq.push(ii(0,0));
	int cnt=-1, ans=0;
	while(cnt<n-1){
		int u=pq.top().second, du=pq.top().first; pq.pop();
		if(b[u]) continue;
		b[u]=1; cnt+=1; ans+=du;
		for(int i=0; i<g[u].size(); i++){
			int v=g[u][i];
			if(b[v]) continue;
			pq.push(ii(a[u][v], v));
		}
	}
	return ans;
}

int main(){
	// freopen("BEAR.inp","r",stdin);
	// freopen("BEAR.out","w",stdout);
	cin>> n>> m;
	for(int i=0; i<n; i++) cin>> c[i];
	for(int i=0; i<m; i++){
		int x,y,val; cin>> x>> y>> val;
		x-=1; y-=1;
		a[x][y] = a[y][x] = 2*val + c[x] + c[y];
		g[x].push_back(y);
		g[y].push_back(x);
	}
	printf("%d\n",prim()+c[0]);
	return 0;
}
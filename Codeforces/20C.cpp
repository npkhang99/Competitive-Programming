#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int N=100009;

int n, m, b[N]={}, tr[N]={};
vector<ii> a[N];
long long d[N]={};

void doc(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++){
		int x,y,val; scanf("%d%d%d",&x,&y,&val);
		a[x].push_back(ii(y,val));
		a[y].push_back(ii(x,val));
	}
}

void trace(int u){
	if(u==0) return;
	trace(tr[u]);
	printf("%d ",u);
}

void dijkstra(){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	for(int i=1; i<=n; i++) d[i] = 10E17;
	d[1] = 0;
	pq.push(ii(0,1));
	while(!pq.empty() && pq.top().second != n){
		int u = pq.top().second, du = pq.top().first; pq.pop();
		if(b[u]) continue;
		b[u] = 1;
		for(int i=0; i<a[u].size(); i++){
			int v = a[u][i].first, val = a[u][i].second;
			if(b[v]) continue;
			if(du + val < d[v]){
				d[v] = du+val;
				tr[v] = u;
				pq.push(ii(d[v],v));
			}
		}
	}
	if(!b[n] && pq.empty()){ printf("-1\n"); return; }
	trace(n);
}

int main(){
	doc();
	dijkstra();
	return 0;
}

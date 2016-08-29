#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<long long,int> lli;

const int N=100009;

int n, m, k, storage[N]={};
long long ans = 10E17, d[N] = {};
vector<lli> a[N];
priority_queue<lli, vector<lli>, greater<lli> > q;

long long dijkstra(){
	for(int i=1; i<=n; i++) d[i] = 10E17;
	while(!q.empty()){
		long long du = q.top().first;
		int u = q.top().second;
		q.pop();
		if(!storage[u]) return du;
		for(int i=0; i<a[u].size(); i++){
			long long val = a[u][i].first;
			int v = a[u][i].second;
			if(du + val < d[v])
				d[v] = du+val,
				q.push(lli(d[v],v));
		}
	}
	return 10E17;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){ printf("-1\n"); return 0; }

	for(int i=0; i<m; i++){
		int x,y,val; scanf("%d%d%d",&x,&y,&val);
		a[x].push_back(lli(val,y));
		a[y].push_back(lli(val,x));
	}
	for(int i=0; i<k; i++){
		int x; scanf("%d",&x);
		storage[x] = 1;
		q.push(lli(0,x));
	}

	ans = min(ans,dijkstra());
	printf("%lld\n",ans==10E17? -1:ans);
	return 0;
}

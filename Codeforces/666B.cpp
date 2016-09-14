#include <bits/stdc++.h>
using namespace std;

const int N=3009;

typedef pair<int,int> ii;

typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, cost[N][N]={}, b[N]={}, optimal = 0, ans[5]={};
vi a[N];
vii v1[N], v2[N];

void doc(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}
}

void BFS(int s, int d[]){
	queue<int> q;
	q.push(s);
	for(int i=1; i<=n; i++) d[i] = -1, b[i] = false;
	d[s] = 0, b[s] = true;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i=0; i<a[u].size(); i++){
			int v = a[u][i];
			if(!b[v]){
				b[v] = true;
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
}

void update(int a, int b, int c, int d){
	optimal = cost[a][b] + cost[b][c] + cost[c][d];
	ans[0] = a, ans[1] = b, ans[2] = c, ans[3] = d;
}

void findPath(int b, int c){
	// if cannot reach c from b -> impossible
	if(cost[b][c]==-1) return;

	// loop through first 5 largest a and d
	// why 5? because duplicates of b and c
	for(int i=0; i<v2[b].size() && i<6; i++)
		for(int j=0; j<v1[c].size() && j<6; j++){
			int a = v2[b][i].second, d = v1[c][j].second;
			if(a==b || a==c || a==d || b==c || b==d || c==d) continue;
			if(optimal < cost[a][b] + cost[b][c] + cost[c][d]) update(a,b,c,d);
		}
}

void xuly(){
	// calculate the cost for every path
	for(int i=1; i<=n; i++) BFS(i,cost[i]);

	// v1 is normal graph, v2 is reversed graph
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(cost[i][j]!=-1) v1[i].push_back(ii(cost[i][j],j));
			if(cost[j][i]!=-1) v2[i].push_back(ii(cost[j][i],j));
		}
		sort(v1[i].begin(), v1[i].end(), greater<ii>());
		sort(v2[i].begin(), v2[i].end(), greater<ii>());
	}

	// loop through every possible b and c
	for(int b=1; b<=n; b++)
		for(int c=1; c<=n; c++)
			findPath(b,c);

	// print answer
	for(int i=0; i<4; i++) printf("%d ",ans[i]);
	printf("\n");
}

int main(){
	doc();
	xuly();
	return 0;
}

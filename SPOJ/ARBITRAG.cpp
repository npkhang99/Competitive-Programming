#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,double> ii;

const int N=39;

int n, m, t=0, possible=0, b[N]={};
double rate, a[N][N], d[N]={};
string name1, name2;
map<string,int> index;
vector<int> graph[N];

void init(){
	index.clear();
	possible = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i==j) a[i][j] = 1.0;
			else a[i][j] = 0.0;
	for(int i=0; i<n; i++) graph[i].clear();
}

int dijsktra(int s){
	priority_queue<ii> q;
	for(int i=0; i<n; i++) b[i]=d[i]=0.0;
	q.push(ii(1.0,s));
	while(!q.empty()){
		int u=q.top().second, du=q.top().first;
		q.pop();
		if(b[u]) continue;
		b[u]=1;
		for(int i=0; i<graph[u].size(); i++){
			int v=graph[u][i];
			if(!b[v] && du*a[u][v] > d[v]){
				d[v] = du*a[u][v];
				q.push(ii(d[v],v));
			}
		}
	}
	for(int i=0; i<n; i++)
		if(d[i]*a[i][s]>1.0){
			// printf("%d - %lf\n",i,d[i]*a[i][s]);
			return 1;
		}
	return 0;
}

int main(){
	while(cin>> n, n){
		init();
		for(int i=0; i<n; i++){
			cin>> name1;
			index[name1] = i;
		}
		cin>> m;
		for(int i=0; i<m; i++){
			cin>> name1>> rate>> name2;
			int x=index[name1], y=index[name2];
			a[x][y] = rate;
			graph[x].push_back(y);
			// a[y][x] = 1.0/rate;
		}
		
		for(int i=0; i<n; i++)
			if(dijsktra(i)){
				possible=1; break; 
			}
		
		if(possible) printf("Case %d: Yes\n",++t);
		else printf("Case %d: No\n",++t);
	}
	return 0;
}
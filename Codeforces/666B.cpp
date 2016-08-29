#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int N=3009;

struct pa{
	int verNum, ver, du, pp[4];
};

int n, cost[N][N]={}, b[N]={};
long long optimal = -10E8;
string ans = "";
vector<int> a[N];

void doc(){
	int m;
	cin>> n>> m;
	for(int i=0; i<m; i++){
		int x,y;
		cin>> x>> y;
		a[x].push_back(y);
	}
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			if(i!=j) cost[i][j]=10E8;
}

void DFS(int root, int u){
	b[u]=true;
	for(int i=0; i<a[u].size(); i++){
		int v = a[u][i];
		cost[root][v] = min(cost[root][u]+1, cost[root][v]);
		if(!b[v]) DFS(root,v);
	}
}

void calcCost(){
	for(int i=1; i<=n; i++){
		for(int j=0; j<=n; j++) b[j]=false;
		DFS(i,i);
	}
}

void findPath(int s){
	queue<pa> q;
	q.push({0,s,0,{s}});
	while(!q.empty()){
		pa curr = q.front(); q.pop();
		if(curr.verNum<3){
			for(int v=1; v<=n; v++)
				
		}
	}
}

void xuly(){
	calcCost();
	for(int i=1; i<=n; i++) findPath(i);
	//cout<< ans;
}

int main(){
	doc();
	xuly();
	return 0;
}

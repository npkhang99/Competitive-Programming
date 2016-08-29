#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int N=100009;

int a[3][N], b[3][N]={}, d[N], n;

void doc(){
	cin>> n;
	for(int i=0; i<3; i++)
		for(int j=1; j<=n; j++){
			cin>> a[i][j];
			b[i][a[i][j]]++;
		}
}

void xuly(){
	int ans=0;
	queue<int> q;
	for(int i=1; i<=n; i++) d[a[0][i]]=i;
	for(int i=1; i<3; i++)
		for(int j=1; j<=n; j++)
			if(!b[i][j]) q.push(j);
	while(!q.empty()){
		int t = q.front(); q.pop();
		int x = d[t];
		if(x==0) continue;
		ans++;
		for(int i=0; i<3; i++){
			b[i][a[i][x]]--;
			if(i>0 && !b[i][a[i][x]]) q.push(a[i][x]);
		}
		d[t]=0;
	}
	cout<< ans;
}

int main(){
	freopen("Sort.inp","r",stdin);
	// freopen("Sort.out","w",stdout);
	doc();
	xuly();
	return 0;
}
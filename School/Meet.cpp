#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=109;

int a[N][N]={}, n, m, s, t;

void doc(){
	cin>> n>> m>> s>> t;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			if(i==j) a[i][j]=0;
			else a[i][j]=10E8;
	for(int i=1; i<=m; i++){
		int x,y,v; cin>> x>> y>> v;
		a[x][y]=v;
	}
}

void floyd(){
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
}

void xuly(){
	floyd();
	int ans=10E8, u=0;
	for(int i=1; i<=n; i++)
		if(a[s][i]<10E8 && a[t][i]<10E8 && ans>max(a[s][i],a[t][i])){
			u=i;
			ans=max(a[s][i],a[t][i]);
		}
	if(u==0) cout<< "0";
	else printf("%d %d",u,ans);
}

int main(){
	freopen("Meet.inp","r",stdin);
	freopen("Meet.out","w",stdout);
	doc();
	xuly();
	return 0;
}
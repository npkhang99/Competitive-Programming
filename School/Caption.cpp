#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <memory.h>
#define inf INT_MAX
#define for(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

int a[200][200], explode[200], n, m, s, t;
//---------------------------------------------------------
void doc(){
	int x,y,val;
	cin>> n>> m>> s>> t;
	for(i,1,n){
		cin>> val;
		if (val==0) explode[i]=inf;
		else explode[i]=val;
	}
	for(i,1,n)
		for(j,1,n)
			if (i==j) a[i][j]=0;
			else a[i][j]=inf;
	for(i,1,m){
		cin>> x>> y>> val;
		a[x][y]=val; a[y][x]=val;
	}
}
//---------------------------------------------------------
int xuly(){
	int L[200], Lmin, u;
	bool b[200];
	if (s==t) return 0;
	for(i,1,n) L[i]=a[s][i];
	memset(b,0,sizeof(b));
	b[s]=true;
	do{
		Lmin=inf; u=0;
		for(i,1,n)
			if (!b[i] && L[i]<Lmin && L[i]<explode[i]){
				Lmin=L[i];
				u=i;
			}
		if (u==0) return -1;
		for(v,1,n)
			if (!b[v] && a[u][v]<inf && L[v]>L[u]+a[u][v] && L[u]+a[u][v]<explode[v])
				L[v]=L[u]+a[u][v];
		b[u]=true;
	}while (!b[t]);
	return L[t];
}
//---------------------------------------------------------
int main(){
	freopen("Caption.inp", "r", stdin);
	freopen("Caption.out", "w", stdout);
	doc();
	cout<< xuly();
	return 0;
}
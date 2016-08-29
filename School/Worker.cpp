#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

#define long long long

const int N=209;

struct worker {
	int h,w;
} a[N];

int n, k;
long t, s, g[N][N];

void doc(){
	int m;
	cin>> n>> m>> k;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			if(i==j) g[i][j]=0;
			else g[i][j]=10E13;
	for(int i=1; i<=m; i++){
		int x,y,v;
		cin>> x>> y>> v;
		g[x][y] = g[y][x] = v;
	}
}

void floyd(){
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
}

void xuly(){
	floyd();
	for(int i=1; i<=k; i++){
		cin>> a[i].h>> a[i].w;
		t+=g[a[i].h][a[i].w];
	}s=t;
	do{	long dec=0;
		for(int i=1; i<=k-1; i++){
			if(dec>0) break;
			for(int j=i+1; j<=k; j++){
				long c1=g[a[i].h][a[i].w], c2=g[a[j].h][a[j].w];
				long _c1=g[a[i].h][a[j].w], _c2=g[a[j].h][a[i].w];
				dec=c1 + c2 - _c1 - _c2;
				if(dec>0) {
					swap(a[i].w,a[j].w);
					break;
				}
			}
		}
		if(dec>0) s-=dec;
		else break;
	}while (dec>0);
	for(int i=1; i<=k; i++)
		printf("%d %d %d %lld\n",i,a[i].h,a[i].w,g[a[i].h][a[i].w]);
	printf("%lld %lld\n",t,s);
}

int main(){
	freopen("Worker.inp","r",stdin);
	// freopen("Worker.out","w",stdout);
	doc();
	xuly();
	return 0;
}

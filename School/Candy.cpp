#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int N=1009;
int n, t, a[N], L[N][N*50];
//---------------------------------------------------------
void doc(){
	cin>> n;
	t=0;
	for(int i=1; i<=n; i++){
		cin>> a[i];
		t+=a[i];
	}
}
//---------------------------------------------------------
void xuly(){
	int w=t/2;
	for(int i=1; i<=w; i++) L[0][i]=0;
	for(int i=1; i<=n; i++) L[i][0]=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=w; j++)
			if(a[i]<=j) L[i][j]=max(L[i-1][j], L[i][j-a[i]]+a[i]);
			else L[i][j]=L[i-1][j];
	cout<< abs(2*L[n][w] - t);
}
//---------------------------------------------------------
int main(){
	freopen("Candy.inp","r",stdin);
	freopen("Candy.out","w",stdout);
	doc();
	xuly();
	return 0;
}
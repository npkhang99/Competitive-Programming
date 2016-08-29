#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

const int N=100009;
int a[N], s[N], n, m;
//---------------------------------------------------------
void doc(){
	fstream f;
	int x;
	f.open("TruDan.inp", ios::in);
	f>> n; m=0;
	while(!f.eof()){
		f>> x;
		s[++m]=x;
	}
	f.close();
}
//---------------------------------------------------------
void xuly(){
	a[0]=0;
	for(int i=1; i<=n; i++){
		a[i]=0;
		for(int j=1; j<=m; j++)
			if (i-s[j]<0) break;
			else if (a[i-s[j]]==0){
					a[i]=1; break;
				}
	}
}
//---------------------------------------------------------
int main(){
	freopen("TruDan.out", "w", stdout);
	doc();
	xuly();
	cout<< a[n];
}
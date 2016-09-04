#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int N=1009;
struct diem{
	int tt, xg, yg;
	double cotg;
}r[N], g[N];
int n;
//---------------------------------------------------------
void doc(){
	cin>> n;
	for(int i=1; i<=n; i++){
		cin>> g[i].xg>> g[i].yg;
		g[i].tt=i;
	}
	for(int i=1; i<=n; i++){
		cin>> r[i].xg>> r[i].yg;
		r[i].tt=i+n;
	}
}
//---------------------------------------------------------
int comp(diem a, diem b){
	return a.cotg<b.cotg;
}
//---------------------------------------------------------
void doitruc(int i, bool xanh){
	int x, y;
	if(xanh){
		for(int j=1; j<=n; j++){
			x=r[j].xg-g[i].xg;
			y=r[j].yg-g[i].yg;
			if(y==0) r[j].cotg=INT_MAX;
			else r[j].cotg=x/y;
		}
	}else{
		for(int j=1; j<=n; j++){
			x=g[j].xg-r[i].xg;
			y=g[j].yg-r[i].yg;
			if(y==0) g[j].cotg=INT_MAX;
			else g[j].cotg=x/y;
		}
	}
}
//---------------------------------------------------------
void xuly(){
	for(int i=1; i<=n; i++){
		doitruc(i,1);
		sort(r+1,r+n+1,comp);
		for(int j=2; j<=n; j++)
			if(r[j].cotg==r[j-1].cotg){
				cout<< g[i].tt<< " "<< r[j-1].tt<< " "<< r[j].tt<< '\n';
				return;
			}
	}
	for(int i=1; i<=n; i++){
		doitruc(i,0);
		sort(g+1,g+n+1,comp);
		for(int j=2; j<=n; j++)
			if(g[j].cotg==g[j-1].cotg){
				cout<< r[i].tt<< " "<< g[j-1].tt<< " "<< g[j].tt<< '\n';
				return;
			}
	}
	cout<< "-1";
}
//---------------------------------------------------------
int main(){
	ios::sync_with_stdio(false);
	doc();
	xuly();
	return 0;
}
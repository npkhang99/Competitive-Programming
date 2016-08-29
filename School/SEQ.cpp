#include <iostream>
#include <algorithm>
#include <fstream>
#define fi "SEQ.inp"
#define fo "SEQ.out"
using namespace std;

int n, k, a[100000];
//---------------------------------------------------------
void docfile(){
	fstream f;
	f.open(fi, ios::in);
	f>> n>> k;
	for(int i=0; i<n; i++)
		f>> a[i];
	f.close();
}
//---------------------------------------------------------
void xuat(int x, int y){
	fstream f;
	f.open(fo, ios::out);
	if (x==y==0) f<< "0 0";
	else if (a[x]-a[y]==k) f<< x<< " "<< y;
	else f<< y<< " "<< x;
	f.close();
}
//---------------------------------------------------------
int binS(int l, int r, int x, int y){
	if(l>r) return(-1);
	int m=a[(l+r)/2];
	if ((m==x) && (((l+r)/2)!=y)) return((l+r)/2);
	else if (x<m) return(binS(l, (l+r)/2-1, x, y));
	else return(binS((l+r)/2+1, r, x, y));
}
//---------------------------------------------------------
void xuly(){
	int deviate, vt;
	sort(a, a+n);
	for (int i=0; i<n; i++){
		deviate=k-a[i];
		vt=binS(0, n, deviate, i);
		if (vt!=-1) xuat(i,vt);
	}
}
//---------------------------------------------------------
int main(){
	docfile;
	xuly();
	return 0;
}
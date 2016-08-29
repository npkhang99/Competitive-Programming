#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define for(i,a,b) for(int i=a; i<=b; i++)
#define sqr(a) pow(a,2)
using namespace std;

struct diem{
	int x,y;
}a[101];
int n;
double r;
//---------------------------------------------------------
double kc(diem d1, diem d2){
	return sqrt(sqr(d1.x-d2.x) + sqr(d1.y-d2.y));
}
//---------------------------------------------------------
double bk(double a, double b, double c){
	if (sqr(a)>=sqr(b)+sqr(c)) return a/2;
	if (sqr(b)>=sqr(a)+sqr(c)) return b/2;
	if (sqr(c)>=sqr(a)+sqr(b)) return c/2;
	double p=(a+b+c)/2;
	double s=sqrt(p*(p-a)*(p-b)*(p-c));
	return (a*b*c) / (4*s);
}
//---------------------------------------------------------
void xuly(){
	double c1,c2,c3;
	r=0;
	for(i,1,n-2)
		for(j,i+1,n-1)
			for(k,j+1,n){
				c1=kc(a[i],a[j]); c2=kc(a[j],a[k]); c3=kc(a[i],a[k]);
				r=max(bk(c1,c2,c3), r);
			}
}
//---------------------------------------------------------
int main(){
	freopen("BanKinh.inp", "r", stdin);
	freopen("BanKinh.out", "w", stdout);
	cin>> n;
	for(i,1,n) cin>> a[i].x>> a[i].y;
	xuly();
	(cout<< fixed).precision(3);
	cout<< r;
}
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#define sqr(a) pow(a,2)
#define for(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

int a, b, c[20000000];
//---------------------------------------------------------
int cal(int x){
	if (x<10) return (sqr(x));
	else return sqr(x%10) + cal(x/10);
}
//---------------------------------------------------------
bool ktra(int x){
	int t[568];
	memset(t,0,sizeof(t));
	while (x!=1 && t[x]==0){
		t[x]=1;
		x=cal(x);
	}
	if (x==1) return true;
	else return false;
}
//---------------------------------------------------------
void xuly(){
	memset(c,0,sizeof(c));
	for(i,1,567){
		if (ktra(i)) c[i]=1;
	}
	if (b>567)
		for(i,568,b)
			c[i]=c[i-1]+c[cal(i)];
}
//---------------------------------------------------------
int main(){
	freopen("Clear.inp", "r", stdin);
	freopen("Clear.out", "w", stdout);
	cin>> a>> b;
	xuly();
	cout<< c[b]-c[a-1];
	return 0;
}
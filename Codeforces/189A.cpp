#include <iostream>
#include <math.h>
using namespace std;

int n, a, b, c, L[8000], d[4000];
//---------------------------------------------------------
void getData(){
	cin>> n>> a>> b>> c;
	for (int i=0; i<=4000; i++){
		L[i]=0; d[i]=0;
	}
}
//---------------------------------------------------------
void xuly(){
	L[0]=1;
	for (int i=0; i<=(n-fmin(a, fmin(b,c))); i++){
		if (L[i]==1){
			L[i+a]=1; L[i+b]=1; L[i+c]=1;
			d[i+a]=fmax(d[i]+1, d[i+a]);
			d[i+b]=fmax(d[i]+1, d[i+b]);
			d[i+c]=fmax(d[i]+1, d[i+c]);
		}
	}
}
//---------------------------------------------------------
int main(){
	getData();
	xuly();
	cout<< d[n];
	return 0;
}
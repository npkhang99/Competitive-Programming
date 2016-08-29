#include <iostream>
#include <math.h>
using namespace std;

int n, a[101], L[101];
//---------------------------------------------------------
void doc(){
	L[0]=0;
	cin>> n;
	for (int i=1; i<=n; i++){
		cin>> a[i];
		L[i]=L[i-1]+a[i];
	}
}
//---------------------------------------------------------
void xuly(){
	int Lmax, up;
	Lmax=0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			up=(i-j+1)-(L[i]-L[j-1]);
			Lmax=fmax(Lmax, L[n]-L[i]+L[j-1]+up);
		}
	}
	cout<< Lmax;
}
//---------------------------------------------------------
int main(){
	doc();
	xuly();
	return(0);
}

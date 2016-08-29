#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int N=1009;

int n, x, a[N];

int main(){
	cin>> n>> x;
	double t=0.0;
	for(int i=0; i<n; i++){
		cin>> a[i]; t+=a[i];
	}
	t=(t<0)?-t:t;
	printf("%d\n",(int)ceil(t/x));
	return 0;
}
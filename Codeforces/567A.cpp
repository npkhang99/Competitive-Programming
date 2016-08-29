#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, a[N];

int abs(int x){
	if(x<0) return -x;
	return x;
}

int main(){
	cin>> n;
	for(int i=0; i<n; i++) cin>> a[i];
	n-=1;
	printf("%d %d\n",abs(a[0]-a[1]),abs(a[0]-a[n]));
	for(int i=1; i<n; i++)
		printf("%d %d\n",min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1])),max(abs(a[i]-a[0]),abs(a[i]-a[n])));
	printf("%d %d\n",abs(a[n-1]-a[n]),abs(a[n]-a[0]));
	return 0;
}
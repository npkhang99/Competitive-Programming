#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, a[2*N], L[2*N]={}, b[2*N]={}, m=0;

int main(){
	// freopen("Beads.inp","r",stdin);
	// freopen("Beads.out","w",stdout);
	cin>> n;
	for(int i=n+1; i<=2*n; i++) cin>> a[i];
	for(int i=1; i<=n; i++) a[i]=a[2*n-i+1];
	for(int i=1; i<=2*n; i++){
		L[i] = lower_bound(b+1, b+m+1, a[i])-b;
		m = max(m,L[i]);
		b[L[i]] = a[i];
	}
	printf("%d\n",m);
	return 0;
}
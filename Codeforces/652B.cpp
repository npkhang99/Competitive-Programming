#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=1009;

int n, a[N];

int comp(int a, int b){
	return a>b;
}

void xuly(){
	int i=0, j=n-1, k=0, ans[N]={};
	while(i<=j){
		if(a[i]>a[j]){ printf("Impossible"); return; }
		ans[k]=a[i]; ans[k+1]=a[j];
		i+=1; j-=1;
		k+=2;
	}
	for(int i=0; i<n; i++) printf("%d ",ans[i]);
}

int main(){
	cin>> n;
	for(int i=0; i<n; i++) cin>> a[i];
	sort(a,a+n);
	xuly();
	return 0;
}
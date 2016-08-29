// SPOJ submission 17211751 (C++ 5) plaintext list. Status: AC, problem QMAX, contest SPOJVN. By mansblacks (Khang), 2016-07-02 05:40:22.
#include <iostream>
#include <stdio.h>
using namespace std;

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

const int N=50009;

int n, m, q, a[N]={}, b[N]={}, it[4*N]={};

void doc(){
	cin>> n>> m;
	for(int i=0; i<m; i++){
		int l,r,k; cin>> l>> r>> k;
		b[l-1]+=k; b[r]-=k;
	}
	int k=0;
	for(int i=0; i<n; i++){
		k+=b[i]; a[i]=k;
	}
}

void createIT(int i, int l, int r){
	if(l==r){ it[i]=a[l]; return; }
	int m=(l+r)/2;
	createIT(2*i,l,m);
	createIT(2*i+1,m+1,r);
	it[i] = max(it[2*i],it[2*i+1]);
}

int findMax(int i, int l, int r, int left, int right){
	if(r<left || l>right) return 0;
	if(l>=left && r<=right) return it[i];
	int m=(l+r)/2;
	int t1=findMax(2*i,l,m,left,right),
		t2=findMax(2*i+1,m+1,r,left,right);
	return max(t1,t2);
}

int main(){
	doc();
	createIT(1,0,n-1);
	cin>> q;
	for(int i=0; i<q; i++){
		int l,r; cin>> l>> r;
		printf("%d\n",findMax(1,0,n-1,l-1,r-1));
	}
	return 0;
}
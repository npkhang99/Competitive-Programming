// SPOJ submission 17211621 (C++ 5) plaintext list. Status: AC, problem NKLINEUP, contest SPOJVN. By mansblacks (Khang), 2016-07-02 05:05:43.
#include <iostream>
#include <stdio.h>
using namespace std;

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

const int N=50009;

int n, q, a[N]={}, itmax[4*N]={}, itmin[4*N]={};

void createIT(int i, int l, int r){
	if(l==r){ itmin[i]=itmax[i]=a[l]; return; }
	int m=(l+r)/2;
	createIT(2*i,l,m);
	createIT(2*i+1,m+1,r);
	itmax[i] = max(itmax[2*i],itmax[2*i+1]);
	itmin[i] = min(itmin[2*i],itmin[2*i+1]);
}

int findMax(int i, int l, int r, int left, int right){
	if(left>r || right<l) return 0;
	if(left<=l && r<=right) return itmax[i];
	int m=(l+r)/2;
	int t1 = findMax(2*i,l,m,left,right),
		t2 = findMax(2*i+1,m+1,r,left,right);
	return max(t1,t2);
}

int findMin(int i, int l, int r, int left, int right){
	if(left>r || right<l) return 2*10E8;
	if(left<=l && r<=right) return itmin[i];
	int m=(l+r)/2;
	int t1 = findMin(2*i,l,m,left,right),
		t2 = findMin(2*i+1,m+1,r,left,right);
	return min(t1,t2);
}

int main(){
	cin>> n>> q;
	for(int i=0; i<n; i++) cin>> a[i];
	createIT(1,0,n-1);
	for(int i=0; i<q; i++){
		int l,r; cin>> l>> r;
		printf("%d\n",findMax(1,0,n-1,l-1,r-1)-findMin(1,0,n-1,l-1,r-1));
	}
	return 0;
}
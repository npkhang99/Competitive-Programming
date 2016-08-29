#include <iostream>
#include <stdio.h>
using namespace std;

const int N=100009;

int n, m;
long long a[N], b[N];

int checkCover(long long x){
	int i=0, j=0;
	while(i<n && j<m){
		if(b[j]-x<=a[i] && b[j]+x>=a[i]) i+=1;
		else j+=1;
	}
	return i==n;
}

int bsearch(long long l, long long r){
	long long mid = (l+r)/2;
	int covered = checkCover(mid);
	// printf("%d %d %d %d\n",l,r,mid,covered);
	if(l>r) return l;
	if(covered) return bsearch(l,mid-1);
	else return bsearch(mid+1,r);
}

int main(){
	cin>> n>> m;
	for(int i=0; i<n; i++) cin>> a[i];
	for(int i=0; i<m; i++) cin>> b[i];
	printf("%d\n",bsearch(0,2000000000));
	return 0;
}

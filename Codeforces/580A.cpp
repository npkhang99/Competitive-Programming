#include <iostream>
#include <stdio.h>
using namespace std;

#define max(a,b) (a>b)?a:b

const int N=100009;

int n, a[N];

int main(){
	cin>> n;
	for(int i=0; i<n; i++) cin>> a[i];
	int ans=1, _max=1;
	for(int i=1; i<n; i++)
		if(a[i]>=a[i-1]){ _max+=1; ans=max(ans,_max); }
		else _max=1;
	printf("%d\n",ans);
	return 0;
}
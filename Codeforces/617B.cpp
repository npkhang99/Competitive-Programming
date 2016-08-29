#include <iostream>
#include <stdio.h>
using namespace std;

const int N=109;

#define long long long

int n, a[N], d[N];

void xuly(){
	int d[N], k=0, vt=1;
	for(int i=1; i<=n; i++)
		if(a[i]==1){
			int vt=i; break;
		}
	for(int i=vt; i<=n; i++)
		if(a[i]==1) d[++k]=1;
		else d[k]++;
	long c=1;
	for(int i=1; i<=k-1; i++){
		c*=d[i];
	}
	cout<< c<< endl;
}

int main(){
	scanf("%d", &n);
	int c=0;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(a[i]==1) c++;
	}
	if(c>1) xuly();
	else printf("%d\n",c);
	return 0;
}

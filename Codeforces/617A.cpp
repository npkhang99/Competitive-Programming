#include <stdio.h>
using namespace std;

const int N=1000009;

#define min(a,b) (a<b)? a:b

int n, L[N];

void xuly(){
	for(int i=0; i<=n; i++) L[i]=N;
	L[0]=0;
	for(int i=0; i<=n; i++)
		for(int j=1; j<=5; j++)
			L[i+j]=min(L[i+j], L[i]+1);
}

int main(){
	scanf("%d", &n);
	xuly();
	printf("%d\n", L[n]);
	return 0;
}

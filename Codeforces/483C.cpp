#include <stdio.h>
using namespace std;

const int N=1E5+9;

int n, k, a[N]={};

int main(){
	scanf("%d%d",&n,&k);
	int i=0, x=1;
	while(k>=0){
		a[i++] = x;
		if(i%2) x+=k--;
		else x-=k--;
	}
	for(int i=0; i<n; i++) printf("%d ",a[i]? a[i]:i+1);
	printf("\n");
	return 0;
}

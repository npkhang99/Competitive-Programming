#include <stdio.h>
using namespace std;

const int d[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int a, b, count=0;

int main(){
	scanf("%d%d", &a, &b);
	for(int i=a; i<=b; i++){
		int n=i, tcount=0;
		while(n!=0){
			tcount+=d[n%10];
			n/=10;
		}
		count+=tcount;
	}
	printf("%d\n", count);
	return 0;
}

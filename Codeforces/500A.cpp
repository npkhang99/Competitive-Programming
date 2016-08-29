#include <iostream>
#include <stdio.h>
using namespace std;

const int N=30009;

int n, t, a[N]={}, b[N]={};

int main(){
	cin>> n>> t;
	for(int i=0; i<n-1; i++) cin>> a[i];
	int i=0; b[0]=1;
	while(i<n-1){
		i+=a[i];
		b[i]=1;
	}
	if(b[t-1]) printf("YES");
	else printf("NO");
	return 0;
}
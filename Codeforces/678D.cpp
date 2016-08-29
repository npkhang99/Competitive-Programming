#include <iostream>
#include <stdio.h>
using namespace std;

const int MOD = 10E8+7;

int n, a, b, x;
long long f, d[1000000]={};

void xuly(){
	int g=0;
	f=x;
	while(g<n){
		f = (a*f+b)%MOD;
		d[g]=f;
		g++;
	}
	for(int i=0; i<n; i++){
		int cnt=0;
		for(int j=0; j<n; j++)
			if(i!=j && d[i]==d[j]) cnt+=1;
		if(cnt>1) printf("%d\n",d[i]);
	}
}

int main(){
	cin>> a>> b>> n>> x;
	xuly();
	return 0;
}
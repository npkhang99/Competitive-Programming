#include <bits/stdc++.h>
using namespace std;

const int N=100009;

int n, a[N]={}, b[9]={};

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		b[a[i]]+=1;
	}
	int ans=0;
	int share = min(b[1],b[3]);
	b[1]-=share; b[3]-=share; ans+=share;
	share = min((int)ceil(b[1]/2.0),b[2]);
	b[1]-=min(b[1],share*2); b[2]-=share; ans+=share;
	share = b[2]/2;
	b[2]-=share*2; ans+=share;
	share = b[1]/4;
	b[1]-=share*4; ans+=share;
	ans+=ceil(b[1]/4.0)+ceil(b[2]/2.0)+b[3]+b[4];
	printf("%d\n",ans);
	return 0;
}

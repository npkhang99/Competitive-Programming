#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=109;

int n, a[2*N], dp[2*N][2*N];

void doc(){
	cin>> n;
	for(int i=1; i<=n; i++){
		int x; cin>> x;
		a[i]=a[i+n]=x;
	}
}

void xuly(){
	for(int i=1; i<=2*n; i++) if(a[i]%2==1) dp[i][i]=1; else dp[i][i]=0;
	for(int x=2; x<=n; x++)
		for(int i=1,j=i+x-1; i<=2*n-x+1; i++,j++)
			dp[i][j]=max(dp[i][i]-dp[i+1][j], dp[j][j]-dp[i][j-1]);
	int ans=0;
	for(int i=1; i<=n; i++)
		if(dp[i][i]-dp[i+1][n+i-1]>0) ans++;
	cout<< ans;
}

int main(){
	freopen("Ivan.inp","r",stdin);
	freopen("Ivan.out","w",stdout);
	doc();
	xuly();
	return 0;
}
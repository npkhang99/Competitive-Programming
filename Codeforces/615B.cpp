#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define long long long

const int N=100009, M=200009;
int n, m, dp[N];
vector<int> a[N];
//---------------------------------------------------------
void doc(){
	cin>> n>> m;
	for(int i=1; i<=m; i++){
		int x,y;
		cin>> x>> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
//---------------------------------------------------------
void xuly(){
	long maxBeauty=-1;
	for(int i=1; i<=n; i++){
		dp[i]=1;
		for(int j=0; j<a[i].size(); j++)
			if(a[i][j]<i) dp[i]=max(dp[i], dp[a[i][j]]+1);
	}
	for(int i=1; i<=n; i++)
		maxBeauty = max(maxBeauty, dp[i]*(long)a[i].size());
	cout<< maxBeauty;
}
//---------------------------------------------------------
int main(){
	doc();
	xuly();
	return 0;
}

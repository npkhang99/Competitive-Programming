#include <bits/stdc++.h>
using namespace std;

const int N=100009;

int n, a[N]={}, b[N]={}, L[N]={}, m=0;
vector<int> ans;

int main(){
	cin>> n;
	for(int i=1; i<=n; i++) cin>> a[i];
	for(int i=1; i<=n; i++){
		L[i] = lower_bound(b+1, b+m+1, a[i])-b;
		m = max(m,L[i]);
		b[L[i]] = a[i];
	}
	printf("%d\n",m);
	for(int i=n; i>0; i--)
		if(L[i]==m){
			ans.push_back(a[i]);
			m-=1;
		}	
	for(int i=ans.size()-1; i>=0; i--) printf("%d ",ans[i]);
	return 0;
}
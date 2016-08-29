// SPOJ submission 17241873 (C++ 5) plaintext list. Status: AC, problem LIS, contest SPOJVN. By mansblacks (Khang), 2016-07-07 19:03:11.
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
	return 0;
} 
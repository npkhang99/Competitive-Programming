#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

const int N=1000009;

int n, a[N], l[N], r[N];
stack<int> s;

int main(){
	// freopen("hist.inp","r",stdin);
	// freopen("hist.out","w",stdout);
	while(scanf("%d",&n), n>0){
		for(int i=0; i<n; i++) scanf("%d",&a[i]);
		
		while(!s.empty()) s.pop();
		s.push(0);
		for(int i=1; i<n; i++){
			while(!s.empty() && a[i]<a[s.top()]){
				r[s.top()] = i-s.top();
				s.pop();
			}
			s.push(i);
		}
		while(!s.empty()){
			r[s.top()] = n-s.top();
			s.pop();
		}
		
		while(!s.empty()) s.pop();
		s.push(n-1);
		for(int i=n-2; i>=0; i--){
			while(!s.empty() && a[i]<a[s.top()]){
				l[s.top()] = s.top()-i-1;
				s.pop();
			}
			s.push(i);
		}
		while(!s.empty()){
			l[s.top()] = s.top();
			s.pop();
		}
		
		long long ans = 0;
		for(int i=0; i<n; i++) ans = max(ans,(long long)((l[i]+r[i])*a[i]));
		printf("%I64d\n",ans);
	}
	return 0;
}
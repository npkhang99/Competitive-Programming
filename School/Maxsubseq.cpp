#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

const int N=10E5+9;

int n, l, r, a[N]={};
long long L[N]={};
multiset<int> bst;

int main(){
	// freopen("Maxsubseq.inp","r",stdin);
	// freopen("Maxsubseq.out","w",stdout);
	scanf("%d %d %d\n",&n,&l,&r);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	L[0] = 0;
	for(int i=1; i<=n; i++) L[i] = L[i-1]+a[i-1];
	long long ans  = 0;
	if(l==r){
		for(int i=l; i<=n; i++) ans = max(ans, L[i]-L[i-l]);
		printf("%I64d\n",ans);
		return 0;
	}
	for(int i=l; i<=n; i++){
		bst.insert(L[i-l]);
		if(i>=r) bst.erase(L[i-r-1]);
		int currMin = *(bst.begin());
		ans = max(ans, L[i]-currMin);
	}
	printf("%I64d\n",ans);
	return 0;
}

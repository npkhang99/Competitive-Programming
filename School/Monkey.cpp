#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> ii;

const int N=109;

int n, m, T, ans=0;
vector<ii> a, b;

int calc(vector<ii> a, int x){
	int ans = 0;
	for(int i=0; i<a.size(); i++){
		int curr = x;
		if(a[i].fi<=curr) ans+=(curr-a[i].fi)/a[i].se+1;
	}
	return ans;
}

void binarySearch(int l, int r){
	if(l>r) return;
	int mid = (l+r)/2,
		x = calc(a,mid),
		y = calc(b,T-mid);
	// printf("%d %d - %d %d - %d %d\n",l,r,mid,T-mid,x,y);
	if(x<=y) ans = max(ans, mid);
	if(x>y) binarySearch(l,mid-1);
	else if(x<=y) binarySearch(mid+1,r);
}

int main(){
	// freopen("Monkey.inp","r",stdin);
	// freopen("Monkey.out","w",stdout);
	scanf("%d\n",&T);
	scanf("%d\n",&n);
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d%d\n",&x,&y);
		a.push_back(ii(x,y));
	}
	scanf("%d\n",&m);
	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d%d\n",&x,&y);
		b.push_back(ii(x,y));
	}
	binarySearch(1,T);
	printf("%d\n",ans);
	return 0;
}
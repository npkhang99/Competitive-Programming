#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, a[N], k;

long long calc(int pos){
	return k-a[pos]<0? a[pos]-k:k-a[pos];
}

long long calc(int pos, int x){
	return x-a[pos]<0? a[pos]-x:x-a[pos];
}

int find(){
	for(int i=0; i<n; i++)
		if(a[i]==k) return i;
		else if(a[i]>k) return i-1;
}

int main(){
	while(scanf("%d%d\n",&n,&k)!=EOF){
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int l = find();
	int r = l+1, cnt=0;
	// printf("%d %d - %d\n",l,r,k);
	long long ans=10E8, tans = 0;
	// for(int i=0; i<n; i++) printf("%d ",a[i]);
	// printf("\n%d %d\n",calc(a[n-1]),calc(a[0]) + calc(a[n-2],a[0]));
	if(l==0)
		ans = min(ans,min(calc(n-1),calc(0) + calc(n-2,a[0])));
	// printf("%d %d\n",calc(0),calc(n-1)+calc(1,a[n-1]));
	if(r==n-1)
		ans = min(ans,min(calc(0),calc(n-1) + calc(1,a[n-1])));
	// printf("%d\n",ans);
	while(cnt++<n-1){
		if(l>-1 && r<n)
			if(calc(l) < calc(r))
				tans+=calc(l), k = a[l--];
			else tans+=calc(r), k = a[r++];
		else if(l>-1)
			tans+=calc(l), k = a[l--];
		else if(r<n)
			tans+=calc(r), k = a[r++];
		// printf("%d %d - %d\n",l,r,k);
	}
	printf("%lld\n",min(ans,tans));
	}
	return 0;
}

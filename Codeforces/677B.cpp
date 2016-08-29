#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int N=100009;

int n, a[N], h, k;

void doc(){
	cin>> n>> h>> k;
	for(int i=0; i<n; i++) cin>> a[i];
	a[n]=(int)10E8+9;
}

void xuly(){
	int i=0, in=0, left=h;
	long long ans=0;
	while(i<=n){
		if(a[i]<=left){
			in+=a[i]; left-=a[i];
			// printf("Put %d : %d %d\n",i,in,left);
			i++;
			continue;
		}
		int t=ceil((a[i]-left)/double(k));
		if(i==n) t=ceil(in/double(k));
		// printf("After %ds : ",t);
		ans+=t;
		in=max(0,in-k*t);
		left=min(h,left+k*t);
		// printf("%d %d - %d\n",in,left,ans);
		if(i==n) break;
	}
	cout<< ans;
}

int main(){
	doc();
	xuly();
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define long long long

const int N=20;

int a[N][N]={}, d[N], n, m;
long ans=0, dp[N][1<<N]={};

void doc(){
	int k;
	scanf("%d%d%d\n",&n,&m,&k);
	for(int i=0; i<n; i++) scanf("%d",&d[i]);
	for(int i=1; i<=k; i++){
		int x,y,val; scanf("%d%d%d",&x,&y,&val);
		a[--x][--y] = val;
	}
}

void xuly(){
	// dp[i][mask] là số năng lượng lớn nhất có thể đạt được
	// nếu ăn các đĩa trong tập mask với đĩa i là đĩa cuối cùng

	// khởi gán các tập chỉ có 1 đĩa
	for(int i=0; i<n; i++) dp[i][1<<i]=d[i];
	// xét tất cả các tập đĩa ăn có thể
	for(int mask=3; mask < (1<<n); mask++){
		int count = __builtin_popcount(mask);
		if(count==1) continue;
		// xét đĩa i là đĩa ăn cuối cùng của mask
		for(int i=0; i<n; i++)
			// kiểm tra xem xem đĩa i có thuộc mask hay không
			if(mask & (1<<i)){
				// lấy pre-mask là tập đĩa đã ăn trước khi ăn đĩa i
				int pre = mask - (1<<i);
				// xét j là đĩa ăn cuối cùng của pre-mask
				for(int j=0; j<n; j++)
					// kiểm tra xem j có thuộc pre-mask
					if(pre & (1<<j))
						// tối ưu dp[i][mask]
						dp[i][mask]=max(dp[i][mask], dp[j][pre] + d[i] + a[j][i]);
			}
	}
	for(int mask=1; mask < (1<<n); mask++)
		// kiểm tra xem số lượng đĩa đã ăn thỏa điều kiện bài toán hay không
		if(__builtin_popcount(mask)==m)
			for(int i=0; i<n; i++)
				// kiểm tra đĩa i có thuộc mask và tối ưu kq
				// với i là đĩa ăn cuối cùng trong mask
				if(mask&(1<<i)) ans=max(ans, dp[i][mask]);
	printf("%lld\n",ans);
}

int main(){
	doc();
	xuly();
	return 0;
}

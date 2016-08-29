#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N=109;

int n, a[9][N]={}, b[N], dp[N][1<<4]={};

int main(){
	while(cin>> n){
		for(int i=1; i<=4; i++)
			for(int j=1; j<=n; j++) a[i][j]=1;
		
		for(int i=1; i<=n; i++){
			int x; cin>> x;
			a[x][i]=0;
			b[i]=x;
		}
		
		for(int mask=1; mask<8; mask++){
			int t=0;
			for(int x=0; x<3; x++)
				if((mask>>x)&1) t+=a[x+1][1];
			dp[1][mask] = t;
		}
		
		for(int i=2; i<=n; i++)
			for(int mask=1; mask<8; mask++){
				int cnt = __builtin_popcount(mask),
					t = cnt + dp[i-1][7];
				for(int x=0; x<3; x++)
					if(((mask>>x)&1) && !a[x+1][i]) t-=1;
				if((mask>>0)&1) t-=a[2][i-2] + a[3][i-1];
				if((mask>>1)&1) t-=a[1][i-2] + a[3][i-2];
				if((mask>>2)&1) t-=a[1][i-2] + a[1][i-1];
				if(((mask>>0)&1) && ((mask>>2)&1)) t+=a[2][i-2];
				dp[i][mask] = t;
				
			}
		
		int cnt=0, ans=0;
		for(int i=1; i<=n; i++){
			for(int mask=0; mask<8; mask++){
				printf("%d ",dp[i][mask]);
				ans = max(ans,dp[i][mask]);
			}
			printf("\n");
		}
		vector<int> v;
		for(int mask=0; mask<8; mask++){
			// ans = (dp[n][mask]>ans)?(cnt=0,printf("\n"),dp[n][mask]):ans;
			// if(dp[n][mask]==ans && (b[n]==0 || (dp[n][mask&(!(1<<(b[n]-1)))]!=dp[n][mask] && mask&(!(1<<(b[n]-1)))<mask))){
			if(dp[n][mask]==ans && (b[n]==0 || !binary_search(v.begin(), v.end(), mask&(~(1<<(b[n]-1)))))){
				// printf("%d\n",mask);
				v.push_back(mask);
				cnt+=1;
			}
		}
		
		printf("%d %d\n",ans,cnt);
	}
	return 0;
}
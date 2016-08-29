#include <stdio.h>

int T, n;

int main(){
	scanf("%d",&T);
	for(int t=0; t<T;){
		int ans = 0, curr;
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d",&curr);
			ans = ans<curr? curr:ans;
		}
		printf("Case %d: %d\n",++t,ans);
	}
	return 0;
}

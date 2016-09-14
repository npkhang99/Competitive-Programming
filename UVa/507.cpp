#include <stdio.h>
using namespace std;

const int N = 20009;

int n, a[N]={}, routes;

int main(){
	scanf("%d",&routes);
	for(int T=0; T<routes;){
		scanf("%d",&n);
		for(int i=1; i<n; i++) scanf("%d",&a[i]);
		int t=0, l=1, r=1, temp = 0, temp_l=1, temp_r=1;
		for(int i=1; i<n; i++){
			if(temp+a[i]>=0){
				temp += a[i];
				temp_r = i;
				if(temp>t || (temp==t && temp_r-temp_l>r-l)) t = temp, l = temp_l, r = temp_r;
				continue;
			}
			temp = 0, temp_l = i+1;
		}
		if(temp>t) t = temp, l = temp_l, r = temp_r;
		if(t==0) printf("Route %d has no nice parts\n",++T);
		else printf("The nicest part of route %d is between stops %d and %d\n",++T,l,r+1);
	}
	return 0;
}

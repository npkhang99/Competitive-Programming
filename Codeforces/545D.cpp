#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, a[N];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int ans=0, totalTime=0;
	for(int i=0; i<n; i++)
		if(totalTime<=a[i]) totalTime+=a[i], ans+=1;
	printf("%d\n",ans);
	return 0;
}

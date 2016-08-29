#include <iostream>
#include <stdio.h>
using namespace std;

const int N=109;

struct activities{
	int sport, code;
}a[N];

int n, ans=0;

int main(){
	scanf("%d\n",&n);
	a[0].sport = a[0].code = 0;
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		int doSport=0, doCode=0;
		if(x==1) doCode = 1;
		if(x==2) doSport = 1;
		if(x==3) doSport = doCode = 1;
		int didSport = a[i-1].sport, didCode = a[i-1].code;
		if((!doSport && !doCode) || (didSport && !doCode) || (didCode && !doSport)){
			ans+=1;
			a[i].sport = a[i].code = 0;
			continue;
		}
		if(didSport){ a[i].code = 1; a[i].sport = 0; }
		else if(didCode){ a[i].sport = 1; a[i].code = 0; }
	}
	for(int i=0; i<=n; i++) printf("%d %d\n",a[i].sport,a[i].code);
	printf("%d\n",ans);
	return 0;
}
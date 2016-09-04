#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int n;
string a;

int abs(int x){ return x<0?-x:x; }

int main(){
	while(cin>> n, n){
		cin>> a;
		int ans = 10E8, drug = 10E8, rest = 10E8;
		for(int i=0; i<n; i++){
			if(a[i]=='.') continue;
			if(a[i]=='Z'){ ans=0; break; }
			if(a[i]=='D') drug = i;
			if(a[i]=='R') rest = i;
			ans = min(ans,abs(drug-rest));
		}
		printf("%d\n",ans);
	}
	return 0;
}

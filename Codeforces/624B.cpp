#include <iostream>
#include <algorithm>
using namespace std;

const int N=29;

int n, a[N], d[N]={};

void doc(){
	cin>> n;
	for(int i=0; i<n; i++) cin>> a[i];
}

void xuly(){
	long long count=0;
	sort(a, a+n);
	for(int i=0; i<n; i++){
		int s=a[i];
		while(s){
			int meet_req=1;
			for(int j=0; j<i; j++)
				if(s==d[j]){
					s--; meet_req=0; break;
				}
			if(meet_req) break;
		}
		count+=s;
		d[i]=s;
	}
	cout<< count;
}

int main(){
	doc();
	xuly();
	return 0;
}

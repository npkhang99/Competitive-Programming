#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int N=200009;

struct film{
	int first, second, index;
}ans;

int n, m, a[N], b[N], c[N];
map<int,int> Count;

void doc(){
	cin>> n;
	for(int i=0; i<n; i++) cin>> a[i];
	cin>> m;
	for(int i=0; i<m; i++) cin>> b[i];
	for(int i=0; i<m; i++) cin>> c[i];
}

void xuly(){
	for(int i=0; i<n; i++)
		if(Count.find(a[i])==Count.end()) Count[a[i]]=1;
		else Count[a[i]]+=1;
	for(int i=0; i<m; i++)
		if(ans.first<Count[b[i]] || (ans.first==Count[b[i]] && ans.second<Count[c[i]])){
		ans.first=Count[b[i]];
		ans.second=Count[c[i]];
		ans.index=i;
	}
	cout<< ans.index+1;
}

int main(){
	doc();
	xuly();
	return 0;
}

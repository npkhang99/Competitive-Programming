#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int N=1000009;

int n, x, y, d[N]={}, t=0;
string st;

void swap(int &x, int &y){
	int t=x;
	x=y; y=t;
}

int main(){
	while(cin>> st){
		printf("Case %d:\n",++t);
		d[0] = int(st[0])-48;
		for(int i=1; i<st.size(); i++) d[i]=d[i-1]+int(st[i])-48;
		cin>> n;
		for(int i=0; i<n; i++){
			cin>> x>> y;
			if(st[x]!=st[y]){ printf("No\n"); continue; }
			if(x>y) swap(x,y);
			if(d[x]==d[y] || d[y]-d[x]==y-x) printf("Yes\n");
			else printf("No\n");
		}
		st = "";
	}
	return 0;
}

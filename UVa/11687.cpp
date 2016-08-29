#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string st;

string toString(int x){
	string st="";
	if(x<10) return st = char(x+48);
	while(x){
		st += char(x%10 + 48);
		x/=10;
	}
	return st;
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>> st, st!="END"){
		string now = toString(st.size()), prev=st;
		int ans=1;
		while(prev != now){
			prev = now;
			now = toString(now.size());
			ans += 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

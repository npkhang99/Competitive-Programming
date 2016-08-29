#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

string st;

void xuly(){
	stack<int> s;
	for(int i=0; i<st.size(); i++)
		if(st[i]==')'){
			cout<< s.top()+1<< " "<< i+1<< endl;
			s.pop();
		}else s.push(i);
}

int main(){
	freopen("Ngoac.inp","r",stdin);
	freopen("Ngoac.out","w",stdout);
	cin>> st;
	xuly();
	return 0;
}

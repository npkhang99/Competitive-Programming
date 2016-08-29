#include <iostream>
#include <stack>
using namespace std;

int a[5], b[5];
//---------------------------------------------------------
void xuly(){
	stack<int> Less, more;
	bool able=true;
	for(int i=1; i<=3; i++)
		if(a[i]>b[i]+1) more.push(i);
		else if(a[i]<b[i]){
			able=false;
			Less.push(i);
		}
	if(able){
		cout<< "YES"; return;
	}
	while(!Less.empty() && !more.empty()){
		int l=Less.top(), m=more.top();
		while(a[l]<b[l] && a[m]>b[m]+1){
			a[m]-=2; a[l]++;
		}
		if(a[l]>=b[l])Less.pop();
		if(a[m]<=b[m]+1)more.pop();
	}
	for(int i=1; i<=3; i++)
		if(a[i]<b[i]){
			cout<< "NO"; return;
		}
	cout<< "YES";
}
//---------------------------------------------------------
int main(){
	cin>> a[1]>> a[2]>> a[3]>> b[1]>> b[2]>> b[3];
	xuly();
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

const int M=19;
int a[M], n, m;
//---------------------------------------------------------
void doc(){
	cin>> n>> m;
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		a[x]++;
	}
}
//---------------------------------------------------------
int counter(){
	int count=0;
	for(int i=1; i<m; i++)
		for(int j=i+1; j<=m; j++)
			count+=a[i]*a[j];
	cout<< count;
}
//---------------------------------------------------------
int main(){
	doc();
	counter();
	return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

int a[2000], n;
//---------------------------------------------------------
void docfile(){
	cin>> n;
	for (int i=1; i<=n; i++){
		cin>> a[i];
	}
}
//---------------------------------------------------------
void xuly(){
	int w;
	w=0 ^ a[1];
	for (int i=2; i<=n; i++)
		w=w ^ a[i];
	if (w==0){
		cout<< "0";
	}else{
		cout<< "1";
	}
}
//---------------------------------------------------------
int main(){
	freopen("NIM.inp", "r", stdin);
	freopen("NIM.out", "w", stdout);
	docfile();
	xuly();
	return 0;
}
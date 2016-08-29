#include <iostream>
#include <stdio.h>
using namespace std;

int n;
//---------------------------------------------------------
int main(){
	freopen("CutSQ.inp","r",stdin);
	freopen("CutSQ.out","w",stdout);
	cin>> n;
	cout<< (n/2+1)*(n-n/2+1);
	return 0;
}
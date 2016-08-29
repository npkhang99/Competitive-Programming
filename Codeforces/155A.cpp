#include <iostream>
#include <stdio.h>
using namespace std;

#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b

int n, x, currMax=0, currMin=0, ans=0;

int main(){
	cin>> n>> x;
	currMax=currMin=x;
	for(int i=1; i<n; i++){
		cin>> x;
		if(x>currMax || x<currMin) ans+=1;
		currMax=max(currMax,x);
		currMin=min(currMin,x);
	}
	cout<< ans;
	return 0;
}
#include <iostream>
using namespace std;

#define long long long

long n, k=1;

int main(){
	cin>> n;
	while(n-k>0) n-=k++;
	cout<< n;
	return 0;
}

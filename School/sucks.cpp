#include <iostream>
using namespace std;

int a,b,i;
int main(){
	cin>> a>> b;
	i=1;
	while ((b+i)*2!=(a+i)) i++;
	cout<< i;
	return 0;
}

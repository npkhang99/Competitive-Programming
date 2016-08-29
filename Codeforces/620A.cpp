#include <iostream>
using namespace std;

#define min(a,b) (a<b)? a:b
#define max(a,b) (a>b)? a:b

int x, y, x0, y0, count=0;

int abs(int x){
	if(x<0) return -x;
	return x;
}

void skip(int i){
	count += i;
	if(x>x0) x-=i; else if(x<x0) x+=i;
	if(y>y0) y-=i; else if(y<y0) y+=i;
}

int main(){
	cin>> x>> y>> x0>> y0;
	skip(min(abs(x-x0), abs(y-y0)));
	skip(max(abs(x-x0), abs(y-y0)));
	cout<< count;
	return 0;
}

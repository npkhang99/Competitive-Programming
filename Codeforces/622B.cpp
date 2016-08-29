#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int h, m, _m;

void doc(){
	string st, _st;
	cin>> st>> _m;
	h=((int)st[0]-48)*10 + ((int)st[1]-48);
	m=((int)st[3]-48)*10 + ((int)st[4]-48);
}

void xuly(){
	m+=_m;
	h=(h+m/60)%24;
	m%=60;
	cout.width(2); cout.fill('0');
	cout<< h<< ":";
	cout.width(2); cout.fill('0');
	cout<< m;
}

int main(){
	doc();
	xuly();
	return 0;
}

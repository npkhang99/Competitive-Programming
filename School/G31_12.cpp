#include <iostream>
#include <fstream>
#define day (30,29,31,28,27,26,25,24,23,22,21,20,19)
using namespace std;

int d, m;
//---------------------------------------------------------
void docfile(){
	fstream f;
	f.open("3112.inp", ios::in);
	f>> d>> m;
	f.close();
}
//---------------------------------------------------------
void xuat(int dn, int mn){
	fstream f;
	f.open("3112.out", ios::out);
	f<< dn<< mn;
	f.close();
}
//---------------------------------------------------------
void xuly(){
	int vtd, vtm;
	if (d<day[m]){
		xuat(day[m],m);
		return;
	}
}
//---------------------------------------------------------
int main(){
	docfile();
	xuly();
	return 0;
}
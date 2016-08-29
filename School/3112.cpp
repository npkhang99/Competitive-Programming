#include <iostream>
#include <fstream>
using namespace std;

int d, m, day[12]={20,21,22,23,24,25,26,27,28,31,29,30}, maxd[12]={31,29,31,30,31,30,31,31,30,31,30,31};
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
	if (dn==0 || mn==0) f<< "LOSS";
	else f<< dn<< " "<< mn;
	f.close();
}
//---------------------------------------------------------
void xuly(){
	int vt;
	if (d<day[m-1]){
		xuat(day[m-1],m);
	}else if (d>day[m]){
			vt=0;
			for (int i=m; i<=11; i++){
				if (d==day[i]) vt=i+1;
			}
			xuat(d,vt);
	}else xuat(0,0);
}
//---------------------------------------------------------
int main(){
	docfile();
	if (day[m]==d+1 || 1<d>maxd[m-1] || 1<m>12) xuat(0,0);
	else xuly();
	return 0;
}
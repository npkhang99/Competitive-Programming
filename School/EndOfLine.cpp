#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int N=109;
int a[N], n;
//---------------------------------------------------------
void doc(){
	ifstream f("EndOfLine.inp",ios::in);
	string str;
	while(f.good()){
		while(getline(f,str)){
			n=0;
			istringstream ss(str);
			while(ss >> a[++n]){}n--;
			for(int i=1; i<=n; i++) cout<< a[i]<< " ";
			cout<< endl;
		}
	}
}
//---------------------------------------------------------
int main(){
	doc();
	return 0;
}
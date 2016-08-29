#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct jumps{
	int time, prac;
	float s;
}a[100005];
int n, ans;
//---------------------------------------------------------
int comp1(jumps a, jumps b){
	return (a.prac < b.prac);
}
//---------------------------------------------------------
float comp2(jumps a, jumps b){
	return (a.s > b.s);
}
//---------------------------------------------------------
void sorts(){
	int l;
	//for(int i=0; i<n; i++) cout<< a[i].time<< " "<< a[i].prac<< " "<< a[i].s<< endl;
	//cout<< endl;
	sort(a, a+n, comp2);
	l=0;
	for(int i=1; i<n; i++)
		if (a[i].time==a[l].time) continue;
		else{sort(a+l, a+i, comp1); l=i;}
	if (l<n-1) sort(a+l, a+n, comp1);
	//for(int i=0; i<n; i++) cout<< a[i].time<< " "<< a[i].prac<< " "<< a[i].s<< endl;
}
//---------------------------------------------------------
void xuly(){
	sorts();
	int pracs=0;
	ans=0;
	for(int i=0; i<n; i++){
		if (pracs<a[i].prac){
			pracs++;
			ans+=a[i].time;
		}else pracs++;
	}//cout<< endl;
}
//---------------------------------------------------------
int main(){
	freopen("Jumps.inp", "r", stdin);
	freopen("Jumps.out", "w", stdout);
	cin>> n; for(int i=0; i<n; i++){cin>> a[i].time>> a[i].prac; a[i].s=(float)a[i].prac/(float)a[i].time;}
	xuly();
	cout<< ans;
	return 0;
}
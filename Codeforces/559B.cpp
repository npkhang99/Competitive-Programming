#include <iostream>
using namespace std;

const int N=100009;
int a[N], b[N], f[N], dem[N], n, m;
//---------------------------------------------------------
void doc(){
	cin>> n>> m;
	for(int i=0; i<n; i++) cin>> f[i];
	for(int i=0; i<m; i++) cin>> b[i];
}
//---------------------------------------------------------
void xuat(bool exist){
	if(exist){
		for(int i=1; i<=n; i++)
			if(dem[i]>1){cout<< "Ambiguity";return;}
		cout<< "Possible"<< endl;
		for(int i=0; i<m; i++) cout<< a[i]<< " ";
	}else cout<< "Impossible";
}
//---------------------------------------------------------
void xuly(){
	bool exist=true;
	for(int i=0; i<m; i++){
		a[i]=f[b[i]]; dem[a[i]]++;
		if(b[i]==f[a[i]]) continue;
		else{exist=false;break;}
	}xuat(exist);
}
//---------------------------------------------------------
int main(){
	doc();
	xuly();
	return 0;
}
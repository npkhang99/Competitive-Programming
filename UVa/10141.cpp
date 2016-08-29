#include <iostream>
#include <string>
using namespace std;

struct criteria{
	int x;
	double y;
	string z;
}ans;

int n, p, met, t=0;
string name;
double price;

int main(){
	while(scanf("%d%d\n",&n,&p), n && p){
		if(t) printf("\n");
		ans.x=0; ans.y=10E8; ans.z="";
		for(int i=0; i<n; i++) getline(cin,name);
		for(int i=0; i<p; i++){
			getline(cin,name);
			scanf("%lf%d\n",&price,&met);
			if(met > ans.x || (met == ans.x && price < ans.y)){
				ans.x = met; ans.y = price; ans.z = name;
			}
			for(int j=0; j<met; j++) getline(cin,name);
		}
		printf("RFP #%d\n%s\n",++t,ans.z.c_str());
	}
	return 0;
}

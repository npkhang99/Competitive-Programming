#include <stdio.h>
#include <string>
using namespace std;

int b1, b2, b3, g1, g2, g3, c1, c2, c3;

int main(){
	while(scanf("%d%d%d%d%d%d%d%d%d\n",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)!=EOF){
		int ans = b2+b3+c1+c3+g1+g2;
		string st = "BCG";
		if (ans>b2+b3+g1+g3+c1+c2) ans = b2+b3+g1+g3+c1+c2, st = "BGC";
		if (ans>c2+c3+b1+b3+g1+g2) ans = c2+c3+b1+b3+g1+g2, st = "CBG";
		if (ans>c2+c3+g1+g3+b1+b2) ans = c2+c3+g1+g3+b1+b2, st = "CGB";
		if (ans>g2+g3+b1+b3+c1+c2) ans = g2+g3+b1+b3+c1+c2, st = "GBC";
		if (ans>g2+g3+c1+c3+b1+b2) ans = g2+g3+c1+c3+b1+b2, st = "GCB";
		printf("%s %d\n",st.c_str(),ans);
	}
	return 0;
}

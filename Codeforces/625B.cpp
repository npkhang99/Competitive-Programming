#include <iostream>
#include <string>
using namespace std;

#define length(st) st.length()

string s1, s2;

void xuly(){
	int i=0, count=0;
	while(i<length(s1)){
		if(s1[i]==s2[0]){
			int j=0;
			while(i<length(s1) && j<length(s2) && s1[i]==s2[j]){
				i++; j++;
			}
			if(j==length(s2)){
				s1[i-1]='#'; count++; continue;
			}else i-=j;
		}i++;
	}
	cout<< count;
}

int main(){
	cin>> s1>> s2;
	xuly();
	return 0;
}

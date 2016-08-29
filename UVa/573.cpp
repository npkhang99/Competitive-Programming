#include <iostream>
#include <stdio.h>
using namespace std;

#define max(a,b) (a>b)?a:b

int h,u,d,f;

int main(){
	while(true){
		cin>> h>> u>> d>> f;
		if(h==0) break;
		double fatigue=u*f/100.0, climbed=0;
		int day=0;
		while(climbed>=0 && climbed<=h){
			climbed+=max(0,u-fatigue*day);
			day+=1;
			if(climbed>h) break;
			climbed-=d;
		}
		if(climbed>h) printf("success on day %d\n",day);
		else printf("failure on day %d\n",day);
	}
}

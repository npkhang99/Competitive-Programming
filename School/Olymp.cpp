#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int N=10E6;

struct student{
	int x,y;
	int r;
}a[N];

int n, c, k;

int comp(student a, student b){
	return a.r<b.r;
}

int main(){
	// freopen("Olymp.inp","r",stdin);
	// freopen("Olymp.out","w",stdout);
	scanf("%d %d %d\n",&n,&c,&k);
	for(int i=0; i<n; i++){
		scanf("%d %d\n",&a[i].x,&a[i].y);
		double t;
		if(a[i].y==0 && a[i].x>=k) t=0;
		else if(a[i].y==0) t=10E8;
		else t = (a[i].y==0)? 10E8:(double(k-a[i].x)/double(a[i].y));
		a[i].r = (int)max(ceil(t),0.0);
	}
	
	sort(a,a+n,comp);
	
	int ans=0;
	for(int i=0; i<n && c>0; i++){
		c-=a[i].r;
		if(c<0) break;
		ans+=1;
	}
	printf("%d\n",ans);
	return 0;
}
